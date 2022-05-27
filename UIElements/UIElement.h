#pragma once
#include <SFML/Graphics.hpp>
#include "../UIBodies/UIElementBody.h"
#include "../UIEvents/UIEvent.h"

using namespace sf;

class UIElement
{
private:
    UIElementBody* body;
    UIEvent* event;
public:
    static void eventCheckLoop(std::vector<UIElement*>& event_list);

    virtual void setEventEnabled(bool active);
    virtual bool isEventEnabled();
    virtual bool eventCheck();
    virtual bool getEventResult();
    virtual void setEventResult(bool new_result);
    virtual void draw();
    virtual ~UIElement();

    UIElement(UIElementBody* new_body, UIEvent* new_event);
    UIElementBody* getBody();
    UIEvent* getEvent();
    void setBody(UIElementBody* new_body);
    void setEvent(UIEvent* new_event);
};