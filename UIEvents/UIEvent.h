#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class UIEvent
{
protected:
    bool event_result;
    bool is_enabled;
    static Vector2i getMousePos(RenderWindow* window);
    static bool isKeyPressed(Keyboard::Key);
    static bool isMouseKeyPressed(Mouse::Button);

public:
    UIEvent();

    virtual void setResult(bool new_result);
    virtual bool getResult();
    virtual void setEnabled(bool active);
    virtual bool isEnabled();

    virtual bool check() = 0;
    virtual ~UIEvent() = 0;
};
