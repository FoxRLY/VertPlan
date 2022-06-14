#include "CornerInterface.h"

CornerInterface::CornerInterface()
{
    is_active = true;
    is_initialized = false;
    window = nullptr;
    pos = {};
    result_delta_text.setString("");
    result_delta_text.setString("");
    input_height_text_box = InputTextBox();
}

bool CornerInterface::isInitialized()
{
    return is_initialized;
}

void CornerInterface::setWindow(RenderWindow* new_window)
{
    window = new_window;
    is_initialized = true;
    input_height_text_box.setWindow(window);
    input_height_text_box.transformInputBox({0,0}, {52,1});
}

void CornerInterface::formatText(TextPresetFunc func, Font &font)
{
    func(result_delta_text, font);
    func(result_height_text, font);
    input_height_text_box.setPreset(func, font);
}

CornerInterface::CornerInterface(RenderWindow* new_window, TextPresetFunc func, Font& font): input_height_text_box(new_window)
{
    window = new_window;
    is_active = true;
    is_initialized = true;
    setPos({0,0});

    func(result_delta_text, font);
    func(result_height_text, font);

    input_height_text_box.setPreset(func, font);
    input_height_text_box.transformInputBox({0,0}, {52,1});

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
}

void CornerInterface::setResultHeight(std::string new_height)
{
    result_height_text.setString(new_height);
}

float CornerInterface::getInputHeight() const
{
    Calculator temp_calc;
    return temp_calc.getSimpleResult(input_height_text_box.getText().getString());
}

void CornerInterface::updateTextComposition()
{
    input_height_text_box.setInputBoxPos({pos.x+2, pos.y+2});
    input_height_text_box.setTextPos({pos.x+2, pos.y+3});

    Vector2f new_delta_pos;
    new_delta_pos.x = pos.x - result_delta_text.getGlobalBounds().width - 2;
    new_delta_pos.y = pos.y + 2;
    result_delta_text.setPosition(new_delta_pos);

    Vector2f new_result_height_pos;
    new_result_height_pos.x = pos.x + 2;
    new_result_height_pos.y = pos.y - result_height_text.getGlobalBounds().height - 2;
    result_height_text.setPosition(new_result_height_pos);
}

void CornerInterface::draw()
{
    if(is_active)
    {
        window->draw(result_height_text);
        window->draw(result_delta_text);
        input_height_text_box.drawTextBox();
        input_height_text_box.drawText();
    }
}

InputTextBox &CornerInterface::getInputBox()
{
    return input_height_text_box;
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