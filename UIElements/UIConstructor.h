#pragma once
#include "UIElement.h"
#include "memory.h"
#include "../UIBodies/RectShapeBody.h"
#include "../UIBodies/DrawingBody.h"
#include "../UIBodies/CameraBody.h"
#include "../UIBodies/GraphDrawingBody.h"
#include "../UIEvents/ButtonEvent.h"
#include "../UIEvents/InputTextBoxEvent.h"
#include "../UIEvents/GraphNavEvent.h"
#include "../UIEvents/DefaultEvent.h"

class UIConstructor
{
private:
public:
    static std::shared_ptr<UIElement> createRectShapeButton(std::weak_ptr<RenderWindow>& window);
    static std::shared_ptr<UIElement> createRectShapeCheckBox(std::weak_ptr<RenderWindow>& window);
    static std::shared_ptr<UIElement> createRectShapeInputTextBox(std::weak_ptr<RenderWindow>& window);
    static std::shared_ptr<UIElement> createDrawingBox(std::weak_ptr<RenderWindow>& window);
    static std::shared_ptr<UIElement> createGraphDrawingBox(std::weak_ptr<RenderWindow>& window);
    static std::shared_ptr<UIElement> createCameraBox(std::weak_ptr<RenderWindow>& window);
};