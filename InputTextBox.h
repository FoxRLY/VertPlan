#pragma once
#include "UIElements/UIConstructor.h"


class InputTextBox
{
private:
    UIElement *text_box;
    Text text;
public:
    static void userInputHandle(std::vector<InputTextBox *> &input_box_list, char input_char);
    explicit InputTextBox(RenderWindow *window);
    ~InputTextBox();
    void setString(const char *new_str);
    void setPreset(void(*preset_func)(Text &, Font &), Font &font);
    void setTextPos(Vector2f pos);
    void setTextPos(float x, float y);
    void setInputBoxPos(Vector2f pos);
    void setInputBoxPos(float x, float y);
    UIElement* getUIElement();
    const Text& getText() const;
    void transformInputBox(Vector2f pos, Vector2f size);
    void drawText();
    void drawTextBox();
};
