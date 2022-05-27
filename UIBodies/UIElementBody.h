#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class UIElementBody
{
protected:
    RenderWindow* window;
public:
    explicit UIElementBody(RenderWindow* new_window);
    void setWindow(RenderWindow* new_window);
    RenderWindow* getWindow();

    virtual bool mouseHover(Vector2f mouse_pos) = 0;
    virtual void transform(Vector2f pos, Vector2f size) = 0;
    virtual FloatRect getGlobalBounds() = 0;
    virtual FloatRect getLocalBounds() = 0;
    virtual void draw() = 0;
    virtual ~UIElementBody() = 0;
};

