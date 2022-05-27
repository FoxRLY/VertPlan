#include "UIElementBody.h"

UIElementBody::~UIElementBody() = default;

UIElementBody::UIElementBody(RenderWindow *new_window)
{
    window = new_window;
}

void UIElementBody::setWindow(RenderWindow *new_window)
{
    window = new_window;
}

RenderWindow *UIElementBody::getWindow()
{
    return window;
}