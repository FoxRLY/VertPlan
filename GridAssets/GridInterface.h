#pragma once
#include "Corners.h"
#include "Cells.h"
#include "Grid.h"

class GridInterface
{
private:
    Grid math;
    Corners corners;
    Cells cells;
public:
    GridInterface(int cell_pixel_size, float cell_size, RenderWindow* window, TextPresetFunc func, Font& font);
    GridInterface(int cell_pixel_size, float cell_size, Vector2i dims, RenderWindow* window, TextPresetFunc func, Font& font);
    void setCellPixelSize(int cell_size);
    void hideCorners();
    void setCellsActive(bool state);
    void setCellSize(float cell_size);
    void setDimensions(Vector2i new_dims);
    void eventCheck();
    void draw();
    void inputEventCheck(char input_char);
    void updateGridStructure();
    void solveGrid();
};

