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
public:
    static std::unique_ptr<UIElement> createRectShapeButton(std::shared_ptr<RenderWindow>& window);
    static std::unique_ptr<UIElement> createRectShapeCheckBox(std::shared_ptr<RenderWindow>& window);
    static std::unique_ptr<UIElement> createRectShapeInputTextBox(std::shared_ptr<RenderWindow>& window);
    static std::unique_ptr<UIElement> createDrawingBox(std::shared_ptr<RenderWindow>& window);
    static std::unique_ptr<UIElement> createGraphDrawingBox(std::shared_ptr<RenderWindow>& window);
    static std::unique_ptr<UIElement> createCameraBox(std::shared_ptr<RenderWindow>& window);
    static std::unique_ptr<UIElement> createRectShapeCheckBoxGridPreset(std::shared_ptr<RenderWindow>& window);
};

void RectShapeBodyPreset(RectShapeBody* button_body);
void RectShapeBodyPresetGrid(RectShapeBody* button_body);
void RectShapeBodyInputBoxPreset(RectShapeBody* button_body);
