#include "GridInterface.h"

void GridInterface::setCellPixelSize(int cell_size)
{
    corners.setCellPixelSize(cell_size);
    cells.setCellPixelSize(cell_size);
}

void GridInterface::setCellSize(float cell_size)
{
    math.setCellSize(cell_size);
}

void GridInterface::setDimensions(Vector2i new_dims)
{
    math.setDimensions({new_dims.x, new_dims.y});
    corners.setDimensions({new_dims.x+1, new_dims.y+1});
    cells.setDimensions(new_dims);
}

void GridInterface::draw()
{
    cells.draw();
    corners.draw();
}

void GridInterface::updateGridStructure()
{
    math.updateCells(cells.getCells());
    corners.updateCornerSwitching(math.getCorners());
}

void GridInterface::solveGrid()
{
    math.updateCorners(corners.getHeightMap());
    math.solveGrid();
}

void GridInterface::inputEventCheck(char input_char)
{
    corners.inputEventCheck(input_char);
}

void GridInterface::eventCheck()
{
    corners.eventCheck();
    cells.eventCheck();
}

GridInterface::GridInterface(int cell_pixel_size, float cell_size, RenderWindow* window, TextPresetFunc func, Font& font):
cells(window, cell_pixel_size),
corners({0,0}, cell_pixel_size, func, font, window),
math()
{
    setCellSize(cell_size);
}

GridInterface::GridInterface(int cell_pixel_size, float cell_size, Vector2i dims, RenderWindow *window, TextPresetFunc func,
                             Font &font):
                             GridInterface(cell_pixel_size, cell_size, window, func, font)
{
    setDimensions(dims);
}