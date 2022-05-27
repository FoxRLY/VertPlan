#pragma once
#include "../UIElements/UIElement.h"

class ButtonEvent : public UIEvent
{
protected:
    bool hold;
    UIElementBody* body;
    RenderWindow* window;
public:
    ButtonEvent(UIElementBody* new_body, RenderWindow* new_window);
    void setBody(UIElementBody* new_body);
    void setWindow(RenderWindow* new_window);
};

class RectShapeButtonEvent : public ButtonEvent
{
public:
    RectShapeButtonEvent(UIElementBody* new_body, RenderWindow* new_window): ButtonEvent(new_body, new_window){};
    bool check() override;
};

class RectShapeCheckBoxEvent : public ButtonEvent
{
public:
    RectShapeCheckBoxEvent(UIElementBody* new_body, RenderWindow* new_window): ButtonEvent(new_body, new_window){};
    bool check() override;
};