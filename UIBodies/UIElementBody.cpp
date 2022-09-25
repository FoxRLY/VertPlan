#include "UIElementBody.h"

#include <utility>

UIElementBody::~UIElementBody() = default;

UIElementBody::UIElementBody(std::shared_ptr<RenderWindow>& new_window): window(new_window)
{
}

void UIElementBody::setWindow(std::shared_ptr<RenderWindow>& new_window)
{
    window = new_window;
}

std::weak_ptr<RenderWindow>& UIElementBody::getWindow()
{
    return window;
}