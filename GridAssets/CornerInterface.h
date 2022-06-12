#pragma once
#include <string>
#include "../UIElements/UIConstructor.h"
#include "../InputTextBox.h"
#include "translator.h"

using TextPresetFunc = void(*)(Text&, Font&);

class CornerInterface
{
private:
    bool is_active;
    RenderWindow* window;
    Vector2f pos;
    Text result_delta_text;
    Text result_height_text;
    InputTextBox input_height_text_box;
    void updateTextComposition();
public:
    CornerInterface(RenderWindow* window, TextPresetFunc func, Font& font);
    CornerInterface(RenderWindow* window, Vector2f new_pos, TextPresetFunc func, Font& font);
    void setPos(Vector2f new_pos);
    void draw();
    void setDeltaText(std::string new_delta);
    void setResultHeight(std::string new_height);
    float getInputHeight() const;
    InputTextBox& getInputBox();
    void eventCheck();
    void setActive(bool state);
    bool inputEventCheck(char input_char);
    Vector2f getPos();
};
