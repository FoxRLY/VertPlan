#include "Cells.h"


void Cells::setDimensions(Vector2i new_dims)
{
    UIElement*** new_cell_matrix = new UIElement**[new_dims.y];
    for(int y = 0; y < new_dims.y; y++)
    {
        new_cell_matrix[y] = new UIElement*[new_dims.x];
        for(int x = 0; x < new_dims.x; x++)
        {
            if(x <= dims.x && y <= dims.y && cell_matrix)
            {
                new_cell_matrix[y][x] = cell_matrix[y][x];
            }
            else
            {
                new_cell_matrix[y][x] = UIConstructor::createRectShapeCheckBox(window);
                new_cell_matrix[y][x]->getBody()->transform({(float)x*cell_pixel_size, (float)y*cell_pixel_size},
                                                            {(float)cell_pixel_size, (float)cell_pixel_size});
                RectShapeBodyPresetGrid((RectShapeBody*)new_cell_matrix[y][x]->getBody());
            }
        }
    }
    if(new_dims.x < dims.x)
    {
        for(int x = new_dims.x-1; x < dims.x-1; x++)
        {
            for(int y = 0; y < new_dims.y; y++)
            {
                delete cell_matrix[y][x];
            }
        }
    }
    if(new_dims.y < dims.y)
    {
        for(int y = new_dims.y-1; y < dims.y-1; y++)
        {
            delete[] cell_matrix[y];
        }
    }
    delete[] cell_matrix;
    cell_matrix = new_cell_matrix;
    dims = new_dims;
}

Cells::Cells(RenderWindow *new_window, int new_size)
{
    dims = {0,0};
    cell_matrix = nullptr;
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
    for(int x = 0; x < dims.x; x++)
    {
        for(int y = 0; y < dims.y; y++)
        {
            cell_matrix[y][x]->eventCheck();
        }
    }
}

void Cells::draw()
{
    for(int x = 0; x < dims.x; x++)
    {
        for(int y = 0; y < dims.y; y++)
        {
            cell_matrix[y][x]->draw();
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
            map[y][x] = !cell_matrix[y][x]->getEventResult();
        }
    }
    return map;
}