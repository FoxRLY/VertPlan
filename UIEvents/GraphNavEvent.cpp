#include "GraphNavEvent.h"

Vector2f GraphNavEvent::getMouseDelta()
{
    return mouse_pos_delta;
}

bool GraphNavEvent::check()
{
    if(!is_enabled)
    {
        event_result = false;
        center_hold = false;
        center_graph_flag = false;
        hover = false;
        return event_result;
    }
    sf::Vector2i pixelPos = getMousePos(window);
    sf::Vector2f worldPos;
    auto window_ptr = window.lock();
    if(window_ptr)
    {
        worldPos = window_ptr->mapPixelToCoords(pixelPos);
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }

    if(body->mouseHover(worldPos))
    {
        hover = true;
        if(isMouseKeyPressed(Mouse::Right))
        {
            if(!center_hold)
            {
                center_graph_flag = true;
                center_hold = true;
            }
            else
            {
                center_graph_flag = false;
            }
        }
        else
        {
            center_graph_flag = false;
            center_hold = false;
        }

        if(isMouseKeyPressed(Mouse::Left))
        {
            if(!event_result)
            {
                prev_mouse_pos = worldPos;
                event_result = true;
            }
            else
            {
                mouse_pos_delta = worldPos - prev_mouse_pos;
                prev_mouse_pos = worldPos;
            }
        }
        else
        {
            event_result = false;
        }
    }
    else
    {
        hover = false;
        event_result = false;
        center_graph_flag = false;
    }
    return event_result;
}