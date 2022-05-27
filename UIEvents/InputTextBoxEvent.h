#pragma once
#include "../UIElements/UIElement.h"
#include "../UIBodies/RectShapeBody.h"


class InputTextBoxEvent : public UIEvent
{
protected:
    RenderWindow* window;
    UIElementBody* body;
    static void addChar(char c, Text& input_text);
public:
    InputTextBoxEvent(UIElementBody* new_body, RenderWindow* new_window);
    static bool inputChar(UIElement* input_box, Text& input_text, char input_char);
};

class RectShapeInputBoxEvent : public InputTextBoxEvent
{
public:
    RectShapeInputBoxEvent(UIElementBody* new_body, RenderWindow* new_window): InputTextBoxEvent(new_body, new_window){}
    bool check() override;
};

