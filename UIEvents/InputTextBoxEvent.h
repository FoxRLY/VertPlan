#pragma once
#include "../UIElements/UIElement.h"
#include "../UIBodies/RectShapeBody.h"


class InputTextBoxEvent : public UIEvent
{
protected:
    std::weak_ptr<RenderWindow> window;
    std::weak_ptr<UIElementBody> body;
    static void addChar(char c, Text& input_text);
public:
    InputTextBoxEvent(std::shared_ptr<UIElementBody>& new_body, std::shared_ptr<RenderWindow>& new_window);
    static bool inputChar(std::shared_ptr<UIElement>& input_box, Text& input_text, char input_char);
};

class RectShapeInputBoxEvent : public InputTextBoxEvent
{
public:
    RectShapeInputBoxEvent(std::shared_ptr<UIElementBody>& new_body, std::shared_ptr<RenderWindow>& new_window): InputTextBoxEvent(new_body, new_window){}
    bool check() override;
};

