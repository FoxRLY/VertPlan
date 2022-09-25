#pragma once
#include <string>
#include <memory>
#include "../UIElements/UIConstructor.h"
#include "InputTextBox.h"

using TextPresetFunc = void(*)(Text&, Font&);

class CornerInterface
{
private:
    bool is_active;
    std::weak_ptr<RenderWindow> window;
    Vector2f pos;
    Text result_delta_text;
    InputTextBox input_height_text_box;
    void updateTextComposition();
public:
    CornerInterface(std::shared_ptr<RenderWindow>& window, TextPresetFunc func, Font& font);
    CornerInterface(std::shared_ptr<RenderWindow>& window, Vector2f new_pos, TextPresetFunc func, Font& font);
    void formatText(TextPresetFunc func, Font& font);
    void setPos(Vector2f new_pos);
    void draw();
    void setDeltaText(std::string& new_delta);
    float getInputHeight() const;
    void eventCheck();
    void setActive(bool state);
    bool inputEventCheck(char input_char);
    Vector2f getPos();
};
