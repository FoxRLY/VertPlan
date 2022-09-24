#include "InputTextBoxEvent.h"

InputTextBoxEvent::InputTextBoxEvent(std::shared_ptr<UIElementBody>&  new_body, std::weak_ptr<RenderWindow>& new_window):
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
    auto rect_body = std::dynamic_pointer_cast<RectShapeBody>(body);
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
    auto window_ptr = window.lock();
    sf::Vector2f worldPos;
    if(window_ptr)
    {
        worldPos = window_ptr->mapPixelToCoords(pixelPos);
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }
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

bool InputTextBoxEvent::inputChar(std::weak_ptr<UIElement>& input_box, Text& input_text, char input_char)
{
    auto input_box_ptr = input_box.lock();
    if(!input_box_ptr)
    {
        throw std::runtime_error("InputBoxEvent: referenced input box doesn't exist anymore");
    }
    if(input_box_ptr->getEventResult())
    {
        InputTextBoxEvent::addChar(input_char, input_text);
        if(input_text.getGlobalBounds().left+input_text.getGlobalBounds().width >= input_box_ptr->getBody()->getGlobalBounds().left+input_box_ptr->getBody()->getGlobalBounds().width)
        {
            InputTextBoxEvent::addChar(8, input_text);
        }
        return true;
    }
    return false;
}