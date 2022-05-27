#include "UIConstructor.h"

UIElement* UIConstructor::createRectShapeButton(RenderWindow* window)
{
    auto* body = new RectShapeBody(window);
    RectShapeBodyPreset(body);
    auto* event = new RectShapeButtonEvent((UIElementBody*)body, window);
    auto* button = new UIElement(body, event);
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
    auto* drawing_box = new UIElement(body, event/*, window*/);
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