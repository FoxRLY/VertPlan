#include "InputTextBox.h"

bool InputTextBox::userInputHandle(InputTextBox& input_box, char input_char)
{
    return InputTextBoxEvent::inputChar(input_box.text_box, input_box.text, input_char);
}

void InputTextBox::userInputHandleVector(std::vector<std::shared_ptr<InputTextBox>>& input_box_list, char input_char) {
    for (auto& input_box: input_box_list) {
        if (InputTextBoxEvent::inputChar(input_box->text_box, input_box->text, input_char)) {
            break;
        }
    }
}

InputTextBox::InputTextBox(std::shared_ptr<RenderWindow>& window) {
text_box = UIConstructor::createRectShapeInputTextBox(window);
text.setString("");
}

void InputTextBox::setString(const char *new_str) {
    text.setString(new_str);
}

void InputTextBox::setPreset(void(*preset_func)(Text &, Font &), Font &font) {
    preset_func(text, font);
}

void InputTextBox::setTextPos(Vector2f pos) {
    text.setPosition(pos);
    text_pos = pos;
}

void InputTextBox::setTextPos(float x, float y) {
    text.setPosition(x, y);
    text_pos = {x,y};
}

void InputTextBox::setInputBoxPos(Vector2f pos) {
    text_box->getBody()->transform(pos, box_size);
}

void InputTextBox::setInputBoxPos(float x, float y) {
    text_box->getBody()->transform(Vector2f(x, y), box_size);
}

std::weak_ptr<UIElement> InputTextBox::getUIElement()
{
    return text_box;
}

const Text& InputTextBox::getText() const
{
    return text;
}

void InputTextBox::transformInputBox(Vector2f pos, Vector2f size)
{
    box_pos = pos;
    box_size = size;
    text_box->getBody()->transform(pos, size);
}

void InputTextBox::drawText()
{
    if(text_box->getBody()->getWindow().expired())
    {
        throw std::runtime_error("No window to draw on");
    }
    text_box->getBody()->getWindow().lock()->draw(text);
}

void InputTextBox::drawTextBox()
{
    text_box->draw();
}