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
    static UIElement* createRectShapeButton(std::weak_ptr<RenderWindow>& window);
    static UIElement* createRectShapeCheckBox(RenderWindow* window);
    static UIElement* createRectShapeInputTextBox(RenderWindow* window);
    static UIElement* createDrawingBox(RenderWindow* window);
    static UIElement* createGraphDrawingBox(RenderWindow* window);
    static UIElement* createCameraBox(RenderWindow* window);
};