#include "GridInterface.h"

void GridInterface::setCellsActive(bool state)
{
    cells.setActive(state);
}

void GridInterface::setCellPixelSize(int cell_size)
{
    corners.setCellPixelSize(cell_size);
    cells.setCellPixelSize(cell_size);
    signs.setCellSize(cell_size);
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
    signs.setDimensions({new_dims.x+1, new_dims.y+1});
}

void GridInterface::draw()
{
    cells.draw();
    corners.draw();
    signs.draw();
    window->draw(zero_work_label);
    window->draw(zero_work_value);
}

void GridInterface::hideCorners()
{
    corners.hideCorners();
}

void GridInterface::updateGridStructure()
{
    math.updateCells(cells.getCells());
    math.solveGrid();
    corners.updateCornerSwitching(math.getCorners());
}

void GridInterface::solveGrid()
{
    math.updateCorners(corners.getHeightMap());
    math.solveGrid();
    corners.updateCornerData(math.getCorners());
    zero_work_value.setString(std::to_string(math.getMedianHeight()));
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

GridInterface::GridInterface(int cell_pixel_size, float cell_size, RenderWindow* new_window, TextPresetFunc func, Font& font):
cells(new_window, cell_pixel_size),
corners({0,0}, cell_pixel_size, func, font, new_window),
math(),
signs(new_window, func, font, {0,0}, {0,0}, cell_pixel_size)
{
    window = new_window;
    func(zero_work_label, font);
    zero_work_label.setString(L"Высота нулевой работы:");
    zero_work_label.setPosition(-25, -100);
    func(zero_work_value, font);
    zero_work_value.setPosition(260, -100);
    setCellSize(cell_size);
}

GridInterface::GridInterface(int cell_pixel_size, float cell_size, Vector2i dims, RenderWindow *window, TextPresetFunc func,
                             Font &font):
                             GridInterface(cell_pixel_size, cell_size, window, func, font)
{
    setDimensions(dims);
}