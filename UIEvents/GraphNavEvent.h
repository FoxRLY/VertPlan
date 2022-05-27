#pragma once
#include "../UIElements/UIElement.h"

class GraphNavEvent : public UIEvent
{
private:
    RenderWindow* window;
    UIElementBody* body;
    bool hover;
    Vector2f prev_mouse_pos;
    Vector2f mouse_pos_delta;
    bool center_hold;
    bool center_graph_flag;

public:
    GraphNavEvent(UIElementBody* new_body, RenderWindow* new_window)
    {
        body = new_body;
        window = new_window;
        center_graph_flag = false;
        center_hold = false;
        hover = false;
    }
    Vector2f getMouseDelta();
    bool getCenterGraphFlag()
    {
        return center_graph_flag;
    }
    bool isHovering()
    {
        return hover;
    }

    bool check() override;
};



