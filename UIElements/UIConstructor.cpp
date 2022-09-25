#include "UIConstructor.h"
#include <memory>

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
    button_body->setOutline(-0.5);
    button_body->setRestingColor(Color(240,240,240,255));
    button_body->setHoverColor(Color(0,102,204,255));
    button_body->setClickColor(Color(120,120,120,255));
    button_body->setDisabledColor(Color(120,120,120,255));
}

void RectShapeBodyInputBoxPreset(RectShapeBody* button_body)
{
    button_body->setOutline(-0.5);
    button_body->setRestingColor(Color(150,150,150,255));
    button_body->setHoverColor(Color(0,102,204,255));
    button_body->setClickColor(Color(120,120,120,255));
    button_body->setDisabledColor(Color(90,90,90,255));
}

std::unique_ptr<UIElement> UIConstructor::createRectShapeButton(std::shared_ptr<RenderWindow>& window)
{
    auto get_body = [&window]() -> std::shared_ptr<UIElementBody>
    {
        auto body = new RectShapeBody(window);
        RectShapeBodyPreset(body);
        return std::shared_ptr<RectShapeBody>(body);
    };
    auto body = get_body();
    auto event = std::shared_ptr<UIEvent>(new RectShapeButtonEvent(body, window));
    auto button = std::make_unique<UIElement>(body, event);
    return button;
}

std::unique_ptr<UIElement> UIConstructor::createRectShapeCheckBox(std::shared_ptr<RenderWindow>& window)
{
    auto get_body = [&window]() -> std::shared_ptr<UIElementBody>
    {
        auto body = new RectShapeBody(window);
        RectShapeBodyPreset(body);
        return std::shared_ptr<RectShapeBody>(body);
    };
    auto body = get_body();
    auto event = std::shared_ptr<UIEvent>(new RectShapeCheckBoxEvent(body, window));
    auto checkbox = std::make_unique<UIElement>(body, event);
    return checkbox;
}

std::unique_ptr<UIElement> UIConstructor::createRectShapeCheckBoxGridPreset(std::shared_ptr<RenderWindow>& window)
{
    auto get_body = [&window]() -> std::shared_ptr<UIElementBody>
    {
        auto body = new RectShapeBody(window);
        RectShapeBodyPresetGrid(body);
        return std::shared_ptr<RectShapeBody>(body);
    };
    auto body = get_body();
    auto event = std::shared_ptr<UIEvent>(new RectShapeCheckBoxEvent(body, window));
    auto checkbox = std::make_unique<UIElement>(body, event);
    return checkbox;
}

std::unique_ptr<UIElement> UIConstructor::createRectShapeInputTextBox(std::shared_ptr<RenderWindow>& window)
{
    auto get_body = [&window]() -> std::shared_ptr<UIElementBody>
    {
        auto body = new RectShapeBody(window);
        RectShapeBodyPreset(body);
        return std::shared_ptr<RectShapeBody>(body);
    };
    auto body = get_body();
    auto event = std::shared_ptr<UIEvent>(new RectShapeInputBoxEvent(body, window));
    auto input_text_box = std::make_unique<UIElement>(body, event);
    return input_text_box;
}

std::unique_ptr<UIElement> UIConstructor::createDrawingBox(std::shared_ptr<RenderWindow>& window)
{
    auto body = std::shared_ptr<UIElementBody>(new DrawingBody(window));
    auto event = std::shared_ptr<UIEvent>(new DefaultEvent());
    auto drawing_box = std::make_unique<UIElement>(body, event);
    return drawing_box;
}

std::unique_ptr<UIElement> UIConstructor::createCameraBox(std::shared_ptr<RenderWindow>& window)
{
    auto body = std::shared_ptr<UIElementBody>(new CameraBody(window));
    auto event = std::shared_ptr<UIEvent>(new GraphNavEvent(body, window));
    auto camera_box = std::make_unique<UIElement>(body, event);
    return camera_box;
}

std::unique_ptr<UIElement> UIConstructor::createGraphDrawingBox(std::shared_ptr<RenderWindow>& window)
{
    auto body = std::shared_ptr<UIElementBody>(new GraphDrawingBody(window));
    auto event = std::shared_ptr<UIEvent>(new DefaultEvent());
    auto graph_drawing_box = std::make_unique<UIElement>(body, event);
    return graph_drawing_box;
}

