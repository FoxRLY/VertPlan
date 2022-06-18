#include "Signs.h"


void Signs::setWindow(RenderWindow *new_window)
{
    window = new_window;
}

void Signs::draw()
{
    for(auto& sign: horizontal_signs)
    {
        window->draw(sign);
    }
    for(auto& sign: vertical_signs)
    {
        window->draw(sign);
    }
}

std::string Signs::intToCharSign(int number)
{
    std::string result;
    do
    {
        result.append(std::string(1,alphabet[(number)%26]));
        number /= 26;
    }
    while(number > 0);
    return result;
}

void Signs::setCellSize(int new_size)
{
    cell_size = new_size;
    setDimensions(dims);
}

void Signs::setDimensions(Vector2i new_dims)
{
    horizontal_signs.resize(new_dims.x);
    vertical_signs.resize(new_dims.y);
    for(int x = 0; x < new_dims.x; x++)
    {
        preset_func(horizontal_signs[x], preset_font);
        horizontal_signs[x].setString(std::to_string(x+1));
        horizontal_signs[x].setPosition(pos.x-5 + x * cell_size + x*1, pos.y-30);
    }
    for(int y = 0; y < new_dims.y; y++)
    {
        preset_func(vertical_signs[y], preset_font);
        vertical_signs[y].setString(intToCharSign(y));
        vertical_signs[y].setPosition(pos.x-30, pos.y-15 + y*cell_size + y*1);
    }
    dims = new_dims;
}

void Signs::setPos(Vector2i new_pos)
{
    pos = new_pos;
    setDimensions(dims);
}

Signs::Signs(RenderWindow *new_window, FontPresetFunc func, Font &font, Vector2i new_pos, Vector2i new_dims, int size):
        preset_font(font)
{
    window = new_window;
    preset_func = func;
    pos = new_pos;
    cell_size = size;
    setDimensions(new_dims);
}