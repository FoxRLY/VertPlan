#include "UIElementBody.h"

#include <utility>

UIElementBody::~UIElementBody() = default;

UIElementBody::UIElementBody(std::weak_ptr<RenderWindow> new_window): window(std::move(new_window))
{
}

void UIElementBody::setWindow(std::weak_ptr<RenderWindow> new_window)
{
    window = std::move(new_window);
}

std::weak_ptr<RenderWindow> UIElementBody::getWindow()
{
    return window.;
}