#pragma once
#include <vector>
#include <memory>
#include "../UIElements/UIConstructor.h"

class Cells
{
private:
    std::vector<std::vector<std::unique_ptr<UIElement>>> cell_matrix;
    Vector2i dims;
    RenderWindow* window;
    int cell_pixel_size;
public:
    Cells(RenderWindow* new_window, int new_size);
    Cells(RenderWindow* new_window, int new_size, Vector2i new_dims);
    void setDimensions(Vector2i new_dims);
    void setCellPixelSize(int size);
    void eventCheck();
    void draw();
    std::vector<std::vector<bool>> getCells();
};

