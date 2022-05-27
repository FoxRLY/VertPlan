#pragma once
#include "../UIElements/UIElement.h"

class DefaultEvent : public UIEvent
{
public:
    DefaultEvent()
    {
        is_enabled = false;
        event_result = false;
    }
    bool check() override;
};
