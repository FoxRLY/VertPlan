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
    dims = new_dims;
    corner_matrix.resize(dims.y);
    for(int y = 0; y < dims.y; y++)
    {
        corner_matrix[y].resize(dims.x, CornerInterface(window, preset_func, font));
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x].setPos({(float)(x * cell_pixel_size), (float)(y * cell_pixel_size)});
        }
    }
}

Corners::Corners(Vector2f new_pos, int new_cell_size, TextPresetFunc new_func, Font& new_font, RenderWindow* new_window): font{new_font}
{
    window = new_window;
    preset_func = new_func;
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
            corner_matrix[y][x].setActive(switch_matrix[y][x].on_edge);
        }
    }
}

// При расчетах дельты
const std::vector<std::vector<CornerInterface>>& Corners::getHeightMap()
{
    return corner_matrix;
}

// Обновление данных о расчетах
void Corners::updateCornerData(const std::vector<std::vector<Corner>>& matrix)
{
    for(int y = 0; y < dims.y; y++)
    {
        for(int x = 0; x < dims.x; x++)
        {
            corner_matrix[y][x].setDeltaText(std::to_string(matrix[y][x].delta));
            corner_matrix[y][x].setResultHeight(std::to_string(matrix[y][x].height + matrix[y][x].delta));
        }
    }
}

void Corners::draw()
{
    for(auto& corner_line: corner_matrix)
    {
        for(auto& corner: corner_line)
        {
            corner.draw();
        }
    }
}

void Corners::eventCheck()
{
    for(auto& corner_line: corner_matrix)
    {
        for(auto& corner: corner_line)
        {
            corner.eventCheck();
        }
    }
}

void Corners::inputEventCheck(char input_char)
{
    for(auto& corner_line: corner_matrix)
    {
        for(auto& corner: corner_line)
        {
            corner.inputEventCheck(input_char);
        }
    }
}



