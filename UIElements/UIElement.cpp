#include "UIElement.h"

UIElement::UIElement(UIElementBody* new_body, UIEvent* new_event)
{
    body = new_body;
    event = new_event;
}

UIElementBody *UIElement::getBody()
{
    return body;
}

UIEvent *UIElement::getEvent()
{
    return event;
}

void UIElement::setBody(UIElementBody *new_body)
{
    body = new_body;
}

void UIElement::setEvent(UIEvent *new_event)
{
    event = new_event;
}

void UIElement::setEventEnabled(bool active)
{
    event->setEnabled(active);
}

void UIElement::eventCheckLoop(std::vector<UIElement*>& event_list)
{
    for(auto element : event_list)
    {
        element->eventCheck();
    }
}

bool UIElement::isEventEnabled()
{
    return event->isEnabled();
}

bool UIElement::eventCheck()
{
    return event->check();
}

bool UIElement::getEventResult()
{
    return event->getResult();
}

void UIElement::setEventResult(bool new_result)
{
    event->setResult(new_result);
}

void UIElement::draw()
{
    body->draw();
}

UIElement::~UIElement()
{
    delete body;
    delete event;
}



