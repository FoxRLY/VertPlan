#include "InputTextBoxEvent.h"

InputTextBoxEvent::InputTextBoxEvent(std::shared_ptr<UIElementBody>&  new_body, std::shared_ptr<RenderWindow>& new_window):
window(new_window),
body(new_body)
{
}

void InputTextBoxEvent::addChar(char c, Text& input_text)
{
    std::string input_str = input_text.getString();
    if(c == 8)
    {
        if(input_str.empty())
        {
            return;
        }
        input_str.pop_back();
    }
    else
    {
        input_str += c;
    }
    input_text.setString(input_str);
}

bool RectShapeInputBoxEvent::check()
{
    if(body.expired())
    {
        throw std::runtime_error("No body to use event on");
    }
    if(window.expired())
    {
        throw std::runtime_error("No window to draw on");
    }
    auto rect_body = std::dynamic_pointer_cast<RectShapeBody>(body.lock());
    if(!is_enabled)
    {
        rect_body->paintDisabled();
        event_result = false;
        return event_result;
    }
    if(isKeyPressed(Keyboard::Enter))
    {
        event_result = false;
        rect_body->paintResting();
        return event_result;
    }
    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos = window.lock()->mapPixelToCoords(pixelPos);
    if(rect_body->mouseHover(worldPos))
    {
        if(isMouseKeyPressed(Mouse::Left))
        {
            if(!event_result)
            {
                event_result = true;
                rect_body->paintHoverToggled();
            }
        }
        else
        {
            if(event_result)
            {
                rect_body->paintHoverToggled();
            }
            else
            {
                rect_body->paintHover();
            }
        }
    }
    else
    {
        if(event_result)
        {
            rect_body->paintToggled();
        }
        else
        {
            rect_body->paintResting();
        }
        if(isMouseKeyPressed(Mouse::Left))
        {
            event_result = false;
            rect_body->paintResting();
        }
    }
    return event_result;
}

bool InputTextBoxEvent::inputChar(std::shared_ptr<UIElement>& input_box, Text& input_text, char input_char)
{
    if(input_box->getEventResult())
    {
        InputTextBoxEvent::addChar(input_char, input_text);
        if(input_text.getGlobalBounds().left+input_text.getGlobalBounds().width >= input_box->getBody()->getGlobalBounds().left+input_box->getBody()->getGlobalBounds().width)
        {
            InputTextBoxEvent::addChar(8, input_text);
        }
        return true;
    }
    return false;
}