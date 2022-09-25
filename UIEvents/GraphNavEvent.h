#pragma once
#include "../UIElements/UIElement.h"
#include <memory>

class GraphNavEvent : public UIEvent
{
private:
    std::weak_ptr<RenderWindow> window;
    std::weak_ptr<UIElementBody> body;
    bool hover;
    Vector2f prev_mouse_pos;
    Vector2f mouse_pos_delta;
    bool center_hold;
    bool center_graph_flag;

public:
    GraphNavEvent(std::shared_ptr<UIElementBody>& new_body, std::shared_ptr<RenderWindow>& new_window)
    {
        body = new_body;
        window = new_window;
        center_graph_flag = false;
        center_hold = false;
        hover = false;
    }
    Vector2f getMouseDelta();
    [[maybe_unused]] [[nodiscard]] bool getCenterGraphFlag() const
    {
        return center_graph_flag;
    }
    [[maybe_unused]] [[nodiscard]] bool isHovering() const
    {
        return hover;
    }

    bool check() override;
};



