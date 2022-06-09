#include "GridInterface.h"

void GridInterface::setDimensions(std::array<int, 2> new_dims)
{
    grid.setDimensions(new_dims);
}

void GridInterface::setCellSize(float new_size)
{
    grid.setCellSize(new_size);
}

GridInterface::GridInterface(RenderWindow* new_window)
{
    window = new_window;
    setDimensions({0,0});
    setCellPixelSize(100);
    setCellSize(0);
    updateStructure();
    updateCalculus();
}

void GridInterface::setCellPixelSize(int size)
{
    cell_pixel_size = size;
}

GridInterface::GridInterface(RenderWindow* new_window,std::array<int, 2> new_dims, float cell_size)
{
    window = new_window;
    setCellPixelSize(100);
    setDimensions(new_dims);
    setCellSize(cell_size);
    updateStructure();
    updateCalculus();
}

void GridInterface::updateStructure()
{
    cell_matrix.resize(grid.getDimensions()[1]);
    for(int cell_line = 0; cell_line < grid.getDimensions()[1]; cell_line++)
    {
        cell_matrix[cell_line].resize(grid.getDimensions()[0]);
        for(int cell_column = 0; cell_column < grid.getDimensions()[0]; cell_column++)
        {
            cell_matrix[cell_line][cell_column] = static_cast<std::unique_ptr<UIElement>>(UIConstructor::createRectShapeCheckBox(window));
            {
                auto cell_body = (RectShapeBody*)cell_matrix[cell_line][cell_column]->getBody();
                cell_body->transform({(float)(cell_column*cell_pixel_size), (float)(cell_line*cell_pixel_size)},{(float)cell_pixel_size, (float)cell_pixel_size});
                RectShapeBodyPresetGrid(cell_body);
            }
        }
    }

    corner_matrix.resize(grid.getDimensions()[1]+1);
    for(int corner_line = 0; corner_line < grid.getDimensions()[1]+1; corner_line++)
    {
        corner_matrix[corner_line].resize(grid.getDimensions()[0]+1, CornerInterface(window));
        for(int corner_column = 0; corner_column < grid.getDimensions()[0]+1; corner_column++)
        {

        }
    }
}

void GridInterface::updateCalculus()
{

}

void GridInterface::draw()
{
    for(auto& cell_line: cell_matrix)
    {
        for(auto& cell: cell_line)
        {
            cell->draw();
        }
    }
    for(auto& corner_line: corner_matrix)
    {
        for(auto& corner: corner_line)
        {
            corner.draw();
        }
    }
}

void GridInterface::eventCheck()
{
    for(auto& corner_line: corner_matrix)
    {
        for(auto& corner: corner_line)
        {
            corner.
        }
    }
}