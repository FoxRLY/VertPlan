#pragma once
#include "../UIElements/UIElement.h"

// Works with ButtonEvent, CheckBoxEvent и InputTextBoxEvent

class RectShapeBody : public UIElementBody
{
private:
    RectangleShape shape;
    Color click_color;
    Color hover_color;
    Color resting_color;
    Color disabled_color;
public:
    explicit RectShapeBody(std::shared_ptr<RenderWindow>& new_window);
    void setClickColor(Color new_color);
    void setHoverColor(Color new_color);
    void setRestingColor(Color new_color);
    void setDisabledColor(Color new_color);
    void setSize(Vector2f new_size);
    [[maybe_unused]] void setShape(RectangleShape& new_shape);
    [[maybe_unused]] RectangleShape& getShape();
    void setPos(Vector2f new_pos);
    void setOutline(float new_outline);
    void paintDisabled();
    void paintToggledDisabled();
    void paintResting();
    void paintToggled();
    void paintHover();
    void paintHoverToggled();

    bool mouseHover(Vector2f mouse_pos) override;
    FloatRect getGlobalBounds() override;
    FloatRect getLocalBounds() override;
    void transform(Vector2f pos, Vector2f size) override;

    void draw() override;
};


