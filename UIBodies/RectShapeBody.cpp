#include "RectShapeBody.h"

RectShapeBody::RectShapeBody(RenderWindow* new_window)
        : shape(Vector2f(0,0)), click_color(Color::Black),
          hover_color(Color::Black), resting_color(Color::Black),
          disabled_color(Color::Black),
          UIElementBody(new_window)
{
}

void RectShapeBody::setClickColor(Color new_color)
{
    click_color = new_color;
}

void RectShapeBody::setHoverColor(Color new_color)
{
    hover_color = new_color;
}

void RectShapeBody::setRestingColor(Color new_color)
{
    resting_color = new_color;
}

void RectShapeBody::setDisabledColor(Color new_color)
{
    disabled_color = new_color;
}

void RectShapeBody::paintDisabled()
{
    shape.setFillColor(resting_color);
    shape.setOutlineColor(disabled_color);
}
void RectShapeBody::paintToggledDisabled()
{
    shape.setFillColor(click_color);
    shape.setOutlineColor(disabled_color);
}
void RectShapeBody::paintResting()
{
    shape.setFillColor(resting_color);
    shape.setOutlineColor(resting_color);
}
void RectShapeBody::paintToggled()
{
    shape.setFillColor(click_color);
    shape.setOutlineColor(resting_color);
}
void RectShapeBody::paintHover()
{
    shape.setFillColor(resting_color);
    shape.setOutlineColor(hover_color);
}
void RectShapeBody::paintHoverToggled()
{
    shape.setFillColor(click_color);
    shape.setOutlineColor(hover_color);
}

void RectShapeBody::setShape(RectangleShape& new_shape)
{
    shape = new_shape;
}

void RectShapeBody::setOutline(float new_outline)
{
    shape.setOutlineThickness(new_outline);
}

void RectShapeBody::setSize(Vector2f new_size)
{
    shape.setSize(new_size);
}

void RectShapeBody::setPos(Vector2f new_pos)
{
    shape.setPosition(new_pos);
}

FloatRect RectShapeBody::getGlobalBounds()
{
    return shape.getGlobalBounds();
}

FloatRect RectShapeBody::getLocalBounds()
{
    return shape.getLocalBounds();
}

RectangleShape& RectShapeBody::getShape()
{
    return shape;
}

bool RectShapeBody::mouseHover(Vector2f mouse_pos)
{
    return shape.getGlobalBounds().contains(mouse_pos);
}

void RectShapeBody::transform(Vector2f pos, Vector2f size)
{
    setPos(pos);
    setSize(size);
}

void RectShapeBody::draw()
{
    window->draw(shape);
}

void RectShapeBodyPreset(RectShapeBody* button_body)
{
    button_body->setOutline(5);
    button_body->setRestingColor(Color(192,192,192,255));
    button_body->setHoverColor(Color(0,204,102,255));
    button_body->setClickColor(Color(170,210,255,255));
    button_body->setDisabledColor(Color(120,120,120,255));
}

void RectShapeBodyPresetGrid(RectShapeBody* button_body)
{
    button_body->setOutline(1);
    button_body->setRestingColor(Color(240,240,240,255));
    button_body->setHoverColor(Color(0,102,204,255));
    button_body->setClickColor(Color(120,120,120,255));
    button_body->setDisabledColor(Color(120,120,120,255));
}
