#include "Corners.h"

void Corners::setPos(Vector2f new_pos)
{
    pos = new_pos;
}

void Corners::setCellPixelSize(int new_cell_size)
{
    cell_pixel_size = new_cell_size;
}

void Corners::setDimensions(Vector2i new_dims)
{
    CornerInterface*** new_corner_matrix = new CornerInterface**[new_dims.y];
    for(int y = 0; y < new_dims.y; y++)
    {
        new_corner_matrix[y] = new CornerInterface*[new_dims.x];
        for(int x = 0; x < new_dims.x; x++)
        {
            if(x < dims.x && y < dims.y && corner_matrix)
            {
                new_corner_matrix[y][x] = corner_matrix[y][x];
            }
            else
            {
                new_corner_matrix[y][x] = new CornerInterface(window, preset_func, font);
                new_corner_matrix[y][x]->setPos({(float)x*cell_pixel_size,(float)y*cell_pixel_size});
            }
        }
    }
    if(new_dims.x < dims.x)
    {
        for(int x = new_dims.x; x < dims.x; x++)
        {
            for(int y = 0; y < new_dims.y; y++)
            {
                delete corner_matrix[y][x];
            }
        }
    }
    if(new_dims.y < dims.y)
    {
        for(int y = new_dims.y; y < dims.y; y++)
        {
            delete[] corner_matrix[y];
        }
    }
    if(corner_matrix)
    {
        delete[] corner_matrix;
    }
    corner_matrix = new_corner_matrix;
    dims = new_dims;
}

Corners::Corners(Vector2f new_pos, int new_cell_size, TextPresetFunc new_func, Font& new_font, RenderWindow* new_window): font{new_font}
{
    window = new_window;
    preset_func = new_func;
    corner_matrix = nullptr;
    setPos(new_pos);
    setCellPixelSize(new_cell_size);
}

Corners::Corners(Vector2f new_pos, int new_cell_size, Vector2i new_dims, TextPresetFunc new_func, Font& new_font, RenderWindow* new_window): Corners(new_pos, new_cell_size, new_func, new_font, new_window)
{
    setDimensions(new_dims);
}

// При включении\выключении клеток
void Corners::updateCornerSwitching(const std::vector<std::vector<Corner>>& switch_matrix)
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x]->setActive(switch_matrix[y][x].on_edge);
        }
    }
}

void Corners::hideCorners()
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x]->setActive(false);
        }
    }
}

// При расчетах дельты
std::vector<std::vector<float>> Corners::getHeightMap()
{
    std::vector<std::vector<float>> height_map;
    height_map.resize(dims.y);
    for(int y = 0; y < dims.y; y++)
    {
        height_map[y].resize(dims.x);
        for(int x = 0; x < dims.x; x++)
        {
            height_map[y][x] = corner_matrix[y][x]->getInputHeight();
        }
    }
    return height_map;
}

// Обновление данных о расчетах
void Corners::updateCornerData(const std::vector<std::vector<Corner>>& matrix)
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x]->setDeltaText(std::to_string(matrix[y][x].delta));
        }
    }
}

void Corners::draw()
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x]->draw();
        }
    }
}

void Corners::eventCheck()
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x]->eventCheck();
        }
    }
}

void Corners::inputEventCheck(char input_char)
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x]->inputEventCheck(input_char);
        }
    }
}



