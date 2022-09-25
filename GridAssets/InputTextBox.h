#pragma once
#include "../UIElements/UIConstructor.h"
#include <memory>

class InputTextBox
{
private:
    std::shared_ptr<UIElement> text_box;
    Vector2f text_pos;
    Vector2f box_pos;
    Vector2f box_size;
    Text text;
public:
    static bool userInputHandle(InputTextBox& input_box, char input_char);
    static void userInputHandleVector(std::vector<std::shared_ptr<InputTextBox>> &input_box_list, char input_char);
    explicit InputTextBox(std::shared_ptr<RenderWindow>& window);
    void setString(const char *new_str);
    void setPreset(void(*preset_func)(Text &, Font &), Font &font);
    void setTextPos(Vector2f pos);
    void setTextPos(float x, float y);
    void setInputBoxPos(Vector2f pos);
    void setInputBoxPos(float x, float y);
    std::weak_ptr<UIElement> getUIElement();
    const Text& getText() const;
    void transformInputBox(Vector2f pos, Vector2f size);
    void drawText();
    void drawTextBox();
};
