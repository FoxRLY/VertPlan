#pragma once
#include <vector>
#include <memory>
#include "../UIElements/UIConstructor.h"

class Cells
{
private:
    std::vector<std::vector<std::unique_ptr<UIElement>>> cell_matrix;
    //UIElement*** cell_matrix;
    Vector2i dims;
    std::weak_ptr<RenderWindow> window;
    int cell_pixel_size;
public:
    Cells(std::shared_ptr<RenderWindow>& new_window, int new_size);
    Cells(std::shared_ptr<RenderWindow>& new_window, int new_size, Vector2i new_dims);
    void setDimensions(Vector2i new_dims);
    void setCellPixelSize(int size);
    void setActive(bool state);
    void eventCheck();
    void draw();
    std::vector<std::vector<bool>> getCells();
};

