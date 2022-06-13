#pragma once
#include <vector>
#include "CornerInterface.h"
#include "Grid.h"

class Corners
{
private:
    CornerInterface*** corner_matrix;
    Vector2i dims;
    Vector2f pos;
    int cell_pixel_size;
    RenderWindow* window;
    TextPresetFunc preset_func;
    Font& font;
public:
    Corners(Vector2f new_pos, int new_cell_size, TextPresetFunc new_func, Font& new_font, RenderWindow* new_window);
    Corners(Vector2f new_pos, int new_cell_size, Vector2i new_dims, TextPresetFunc new_func, Font& new_font, RenderWindow* new_window);
    void setDimensions(Vector2i new_dims);
    void setPos(Vector2f new_pos);
    void setCellPixelSize(int new_cell_size);
    void updateCornerSwitching(const std::vector<std::vector<Corner>>& matrix);
    const std::vector<std::vector<CornerInterface>>& getHeightMap();
    void updateCornerData(const std::vector<std::vector<Corner>>& matrix);
    void eventCheck();
    void inputEventCheck(char input_char);
    void draw();
};
