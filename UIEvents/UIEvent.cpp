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

Vector2i UIEvent::getMousePos(const std::weak_ptr<RenderWindow>& window)
{
    auto window_ptr = window.lock();
    if(!window_ptr)
    {
        throw std::runtime_error("No window to draw on");
    }
    return Mouse::getPosition(*window_ptr);
}

bool UIEvent::isKeyPressed(Keyboard::Key key)
{
    return Keyboard::isKeyPressed(key);
}

bool UIEvent::isMouseKeyPressed(Mouse::Button button)
{
    return Mouse::isButtonPressed(button);
}