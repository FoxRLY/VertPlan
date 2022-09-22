#include "UIConstructor.h"
#include <memory>

void RectShapeBodyPreset(std::shared_ptr<RectShapeBody>& button_body)
{
    button_body->setOutline(5);
    button_body->setRestingColor(Color(192,192,192,255));
    button_body->setHoverColor(Color(0,204,102,255));
    button_body->setClickColor(Color(170,210,255,255));
    button_body->setDisabledColor(Color(120,120,120,255));
}

void RectShapeBodyPresetGrid(std::shared_ptr<RectShapeBody>& button_body)
{
    button_body->setOutline(-0.5);
    button_body->setRestingColor(Color(240,240,240,255));
    button_body->setHoverColor(Color(0,102,204,255));
    button_body->setClickColor(Color(120,120,120,255));
    button_body->setDisabledColor(Color(120,120,120,255));
}

void RectShapeBodyInputBoxPreset(std::shared_ptr<RectShapeBody>& button_body)
{
    button_body->setOutline(-0.5);
    button_body->setRestingColor(Color(150,150,150,255));
    button_body->setHoverColor(Color(0,102,204,255));
    button_body->setClickColor(Color(120,120,120,255));
    button_body->setDisabledColor(Color(90,90,90,255));
}

UIElement* UIConstructor::createRectShapeButton(std::weak_ptr<RenderWindow>& window)
{
    auto body = std::make_shared<RectShapeBody>(window);
    RectShapeBodyPreset(body);
    auto event = new RectShapeButtonEvent(body, window);
    auto button = new UIElement(body, event);
    return button;
}

UIElement* UIConstructor::createRectShapeCheckBox(RenderWindow* window)
{
    auto* body = new RectShapeBody(window);
    RectShapeBodyPreset(body);
    auto* event = new RectShapeCheckBoxEvent(body, window);
    auto* checkbox = new UIElement(body, event);
    return checkbox;
}

UIElement* UIConstructor::createRectShapeInputTextBox(RenderWindow *window)
{
    auto* body = new RectShapeBody(window);
    RectShapeBodyPreset(body);
    auto* event = new RectShapeInputBoxEvent(body, window);
    auto* input_text_box = new UIElement(body, event);
    return input_text_box;
}

UIElement* UIConstructor::createDrawingBox(RenderWindow *window)
{
    auto* body = new DrawingBody(window);
    auto* event = new DefaultEvent();
    auto* drawing_box = new UIElement(body, event);
    return drawing_box;
}

UIElement* UIConstructor::createCameraBox(RenderWindow *window)
{
    auto* body = new CameraBody(window);
    auto* event = new GraphNavEvent(body, window);
    auto camera_box = new UIElement(body, event);
    return camera_box;
}

UIElement* UIConstructor::createGraphDrawingBox(RenderWindow *window)
{
    auto* body = new GraphDrawingBody(window);
    auto* event = new DefaultEvent();
    auto* graph_drawing_box = new UIElement(body, event);
    return graph_drawing_box;
}

