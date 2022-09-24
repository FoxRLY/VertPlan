#pragma once
#include "../UIElements/UIElement.h"
#include "../UIBodies/RectShapeBody.h"


class InputTextBoxEvent : public UIEvent
{
protected:
    std::weak_ptr<RenderWindow> window;
    std::shared_ptr<UIElementBody> body;
    static void addChar(char c, Text& input_text);
public:
    InputTextBoxEvent(std::shared_ptr<UIElementBody>&  new_body, std::weak_ptr<RenderWindow>& new_window);
    static bool inputChar(std::weak_ptr<UIElement>& input_box, Text& input_text, char input_char);
};

class RectShapeInputBoxEvent : public InputTextBoxEvent
{
public:
    RectShapeInputBoxEvent(std::shared_ptr<UIElementBody>& new_body, std::weak_ptr<RenderWindow>& new_window): InputTextBoxEvent(new_body, new_window){}
    bool check() override;
};

