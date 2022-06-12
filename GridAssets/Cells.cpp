#include "Cells.h"


void Cells::setDimensions(Vector2i new_dims)
{
    cell_matrix.resize(new_dims.y);
    for(auto& cell_line: cell_matrix)
    {
        cell_line.resize(new_dims.x);
        for(int x = dims.x-1; x < new_dims.x; x++)
        {
            auto new_cell = UIConstructor::createRectShapeCheckBox(window);
            cell_line[x] = static_cast<std::unique_ptr<UIElement>>(new_cell);
        }
    }
}

Cells::Cells(RenderWindow *new_window, int new_size)
{
    dims = {};
    window = new_window;
    setCellPixelSize(new_size);
}

Cells::Cells(RenderWindow *new_window, int new_size, Vector2i new_dims): Cells(new_window, new_size)
{
    setDimensions(new_dims);
}

void Cells::setCellPixelSize(int size)
{
    cell_pixel_size = size;
}

void Cells::eventCheck()
{
    for(auto& cell_line: cell_matrix)
    {
        for(auto& cell: cell_line)
        {
            cell->eventCheck();
        }
    }
}

void Cells::draw()
{
    for(auto& cell_line: cell_matrix)
    {
        for(auto& cell: cell_line)
        {
            cell->draw();
        }
    }
}

std::vector<std::vector<bool>> Cells::getCells()
{
    std::vector<std::vector<bool>> map;
    map.resize(dims.y);
    for(int y = 0; y < dims.y; y++)
    {
        map[y].resize(dims.x);
        for(int x = 0; x < dims.x; x++)
        {
            map[y][x] = cell_matrix[y][x]->getEventResult();
        }
    }
    return map;
}