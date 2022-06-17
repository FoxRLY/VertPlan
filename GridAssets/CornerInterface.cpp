#include "CornerInterface.h"


void CornerInterface::formatText(TextPresetFunc func, Font &font)
{
    func(result_delta_text, font);
    input_height_text_box.setPreset(func, font);
}

CornerInterface::CornerInterface(RenderWindow* new_window, TextPresetFunc func, Font& font): input_height_text_box(new_window)
{
    window = new_window;
    is_active = true;
    setPos({0,0});

    func(result_delta_text, font);

    input_height_text_box.setPreset(func, font);
    input_height_text_box.transformInputBox({0,0}, {90,30});
    RectShapeBodyInputBoxPreset((RectShapeBody*)input_height_text_box.getUIElement()->getBody());

    updateTextComposition();
}

CornerInterface::CornerInterface(RenderWindow* new_window, Vector2f new_pos, TextPresetFunc func, Font& font): CornerInterface(new_window, func, font)
{
    setPos(new_pos);
    updateTextComposition();
}

void CornerInterface::setPos(Vector2f new_pos)
{
    pos = new_pos;
    updateTextComposition();
}

void CornerInterface::setDeltaText(std::string new_delta)
{
    result_delta_text.setString(new_delta);
    updateTextComposition();
}

float CornerInterface::getInputHeight() const
{
    std::string result_str = input_height_text_box.getText().getString();
    float result = 0;
    try {
        result = std::stof(result_str);
    } catch(...) {

    }
    return result;
}

void CornerInterface::updateTextComposition()
{
    input_height_text_box.setInputBoxPos({pos.x+10, pos.y+10});
    input_height_text_box.setTextPos({pos.x+10, pos.y+11});

    Vector2f new_delta_pos;
    new_delta_pos.x = pos.x + 10;
    new_delta_pos.y = pos.y + result_delta_text.getGlobalBounds().height + 30;
    result_delta_text.setPosition(new_delta_pos);
}

void CornerInterface::draw()
{
    if(is_active)
    {
        input_height_text_box.drawTextBox();
        input_height_text_box.drawText();
        window->draw(result_delta_text);
    }
}

void CornerInterface::eventCheck()
{
    input_height_text_box.getUIElement()->eventCheck();
}

bool CornerInterface::inputEventCheck(char input_char)
{
    std::vector<InputTextBox *> buffer = {&input_height_text_box};
    std::string prev_string = input_height_text_box.getText().getString();
    InputTextBox::userInputHandle(buffer, input_char);
    return prev_string != input_height_text_box.getText().getString();
}

void CornerInterface::setActive(bool state)
{
    is_active = state;
    input_height_text_box.getUIElement()->setEventEnabled(is_active);
}

Vector2f CornerInterface::getPos()
{
    return pos;
}