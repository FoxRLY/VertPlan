#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "../UIBodies/UIElementBody.h"
#include "../UIEvents/UIEvent.h"

using namespace sf;

class UIElement
{
private:
    std::shared_ptr<UIElementBody> body;
    std::shared_ptr<UIEvent> event;
public:
    static void eventCheckLoop(std::vector<std::shared_ptr<UIElement>>& event_list);

    virtual void setEventEnabled(bool active);
    virtual bool isEventEnabled();
    virtual bool eventCheck();
    virtual bool getEventResult();
    virtual void setEventResult(bool new_result);
    virtual void draw();
    virtual ~UIElement() = default;

    UIElement(std::shared_ptr<UIElementBody>& new_body, std::shared_ptr<UIEvent>& new_event);
    std::shared_ptr<UIElementBody> getBody();
    std::shared_ptr<UIEvent> getEvent();

    [[maybe_unused]] void setBody(std::shared_ptr<UIElementBody>& new_body);
    [[maybe_unused]] void setEvent(std::shared_ptr<UIEvent>& new_event);
};