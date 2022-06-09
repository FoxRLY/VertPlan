#pragma once
#include <string>
#include "UIElements/UIConstructor.h"
#include "InputTextBox.h"
#include "translator.h"

class CornerInterface
{
private:
    bool is_active = true;
    RenderWindow* window;
    Vector2f pos;
    Text result_delta_text;
    Text result_height_text;
    InputTextBox input_height_text_box;
    void updateTextComposition();
public:
    explicit CornerInterface(RenderWindow* window);
    CornerInterface(RenderWindow* window, Vector2f new_pos);
    void setPos(Vector2f new_pos);
    void draw();
    void setDeltaText(std::string new_delta);
    void setResultHeight(std::string new_height);
    float getInputHeight();
    InputTextBox& getInputBox();
    void eventCheck();
    bool inputEventCheck(char input_char)
};
