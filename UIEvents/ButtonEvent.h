#pragma once
#include "../UIElements/UIElement.h"

class ButtonEvent : public UIEvent
{
protected:
    bool hold;
    std::weak_ptr<RenderWindow> window;
    std::shared_ptr<UIElementBody> body;
public:
    ButtonEvent(std::shared_ptr<UIElementBody>& new_body, std::weak_ptr<RenderWindow>& new_window);
    [[maybe_unused]] void setBody(std::shared_ptr<UIElementBody>& new_body);
    [[maybe_unused]] void setWindow(std::weak_ptr<RenderWindow>& new_window);
};

class RectShapeButtonEvent : public ButtonEvent
{
public:
    RectShapeButtonEvent(std::shared_ptr<UIElementBody>& new_body, std::weak_ptr<RenderWindow>& new_window): ButtonEvent(new_body, new_window){};
    bool check() override;
};

class RectShapeCheckBoxEvent : public ButtonEvent
{
public:
    RectShapeCheckBoxEvent(std::shared_ptr<UIElementBody>& new_body, std::weak_ptr<RenderWindow>& new_window): ButtonEvent(new_body, new_window){};
    bool check() override;
};