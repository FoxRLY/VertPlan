#include "UIEvent.h"

UIEvent::~UIEvent() = default;

UIEvent::UIEvent()
{
    event_result = false;
    is_enabled = true;
}

void UIEvent::setResult(bool new_result)
{
    event_result = new_result;
}

void UIEvent::setEnabled(bool active)
{
    is_enabled = active;
}

bool UIEvent::getResult()
{
    return event_result;
}

bool UIEvent::isEnabled()
{
    return is_enabled;
}

Vector2i UIEvent::getMousePos(RenderWindow* window)
{
    return Mouse::getPosition(*window);
}

bool UIEvent::isKeyPressed(Keyboard::Key key)
{
    return Keyboard::isKeyPressed(key);
}

bool UIEvent::isMouseKeyPressed(Mouse::Button button)
{
    return Mouse::isButtonPressed(button);
}