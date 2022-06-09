#pragma once
#include <array>
#include <vector>
#include <memory>
#include "UIElements/UIConstructor.h"
#include "CornerInterface.h"
#include "InputTextBox.h"
#include "Grid.h"


class GridInterface
{
private:
    Grid grid;
    int cell_pixel_size;
    RenderWindow* window;
    std::vector<std::vector<CornerInterface>> corner_matrix;
    std::vector<std::vector<std::unique_ptr<UIElement>>> cell_matrix;
public:
    explicit GridInterface(RenderWindow* new_window);
    explicit GridInterface(RenderWindow* new_window,std::array<int,2> new_dims, float cell_size);
    void setDimensions(std::array<int,2> new_dims);
    void setCellSize(float new_size);
    void updateStructure();
    void updateCalculus();
    void setCellPixelSize(int size);
    void eventCheck();
    void inputEventCheck(char input_char);
    void draw();
};

