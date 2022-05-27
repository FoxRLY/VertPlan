#include "ButtonEvent.h"
#include "../UIBodies/RectShapeBody.h"

ButtonEvent::ButtonEvent(UIElementBody *new_body, RenderWindow *new_window)
{
    hold = false;
    body = new_body;
    window = new_window;
}

void ButtonEvent::setBody(UIElementBody *new_body)
{
    body = new_body;
}

void ButtonEvent::setWindow(RenderWindow *new_window)
{
    window = new_window;
}

bool RectShapeButtonEvent::check()
{
    auto* rect_body = (RectShapeBody*)body;
    if(!is_enabled)
    {
        rect_body->paintDisabled();
        hold = false;
        event_result = false;
        return event_result;
    }

    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
    if(rect_body->mouseHover(worldPos))
    {
        if(isMouseKeyPressed(Mouse::Left))
        {
            if(!hold)
            {
                rect_body->paintHoverToggled();
                event_result = true;
                hold = true;
            }
            else
            {
                event_result = false;
            }
        }
        else
        {
            rect_body->paintHover();
            event_result = false;
            hold = false;
        }
    }
    else
    {
        rect_body->paintResting();
        event_result = false;
    }
    return event_result;
}

bool RectShapeCheckBoxEvent::check()
{
    auto* rect_body = (RectShapeBody*)body;
    if(!is_enabled)
    {
        if(event_result)
        {
            rect_body->paintToggledDisabled();
        }
        else
        {
            rect_body->paintDisabled();
        }
        return event_result;
    }

    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
    if(rect_body->mouseHover(worldPos))
    {
        if(isMouseKeyPressed(Mouse::Left))
        {
            if(!hold)
            {
                event_result = !event_result;
                if(event_result)
                {
                    rect_body->paintHoverToggled();
                }
                else
                {
                    rect_body->paintHover();
                }
                hold = true;
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
            hold = false;
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
    }
    return event_result;
}
