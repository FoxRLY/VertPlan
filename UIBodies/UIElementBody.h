#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;

class UIElementBody
{
protected:
    std::weak_ptr<RenderWindow> window;
public:
    explicit UIElementBody(std::shared_ptr<RenderWindow>& new_window);
    void setWindow(std::shared_ptr<RenderWindow>& new_window);
    std::weak_ptr<RenderWindow>& getWindow();

    virtual bool mouseHover(Vector2f mouse_pos) = 0;
    virtual void transform(Vector2f pos, Vector2f size) = 0;
    virtual FloatRect getGlobalBounds() = 0;
    virtual FloatRect getLocalBounds() = 0;
    virtual void draw() = 0;
    virtual ~UIElementBody() = 0;
};

