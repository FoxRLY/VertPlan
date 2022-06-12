#include "InputTextBox.h"

void InputTextBox::userInputHandle(std::vector<InputTextBox *> &input_box_list, char input_char) {
    for (auto input_box: input_box_list) {
        if (InputTextBoxEvent::inputChar(input_box->text_box, input_box->text, input_char)) {
            break;
        }
    }
}

InputTextBox::InputTextBox(RenderWindow *window) {
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
}

void InputTextBox::setTextPos(float x, float y) {
    text.setPosition(x, y);
}

void InputTextBox::setInputBoxPos(Vector2f pos) {
    text_box->getBody()->transform(pos, Vector2f(text_box->getBody()->getGlobalBounds().width,
                                                 text_box->getBody()->getGlobalBounds().height));
}

void InputTextBox::setInputBoxPos(float x, float y) {
    text_box->getBody()->transform(Vector2f(x, y), Vector2f(text_box->getBody()->getGlobalBounds().width,
                                                            text_box->getBody()->getGlobalBounds().height));
}

UIElement* InputTextBox::getUIElement()
{
    return text_box;
}

const Text& InputTextBox::getText() const
{
    return text;
}

void InputTextBox::transformInputBox(Vector2f pos, Vector2f size)
{
    text_box->getBody()->transform(pos, size);
}

void InputTextBox::drawText()
{
    text_box->getBody()->getWindow()->draw(text);
}

void InputTextBox::drawTextBox()
{
    text_box->draw();
}

InputTextBox::~InputTextBox()
{
    delete text_box;
}