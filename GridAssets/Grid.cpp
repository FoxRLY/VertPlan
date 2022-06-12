#include "Grid.h"

float Grid::getCellSize() const
{
    return cell_size;
}

void Grid::setCellSize(float new_size)
{
    cell_size = new_size;
}

void Grid::solveCorners()
{
    one.clear();
    two.clear();
    three.clear();
    four.clear();
    for(int y = 0; y < dimensions[1]+1; y++)
    {
        for(int x = 0; x < dimensions[0]+1; x++)
        {
            int left_up = !(x-1 < 0 || y-1 < 0) && grid_cells[dimensions[0] * (y-1) + (x-1)];
            int left_down = !(x-1 < 0 || y >= dimensions[1]) && grid_cells[dimensions[0] * y + (x-1)];
            int right_up = !(x >= dimensions[0] || y-1 < 0) && grid_cells[dimensions[0] * (y-1) + x];
            int right_down = !(x >= dimensions[0] || y >= dimensions[1]) && grid_cells[dimensions[0] * y + x];
            grid_corners[y][x].on_edge = left_up + left_down + right_up + right_down;
            switch(grid_corners[y][x].on_edge)
            {
                case 1:
                    one.push_back(&grid_corners[y][x]);
                    break;
                case 2:
                    two.push_back(&grid_corners[y][x]);
                    break;
                case 3:
                    three.push_back(&grid_corners[y][x]);
                    break;
                case 4:
                    four.push_back(&grid_corners[y][x]);
                    break;
            }
        }
    }
}

void Grid::solveMedian()
{
    float one_sum = 0;
    for(auto corner : one)
    {
        one_sum += corner->height;
    }
    float two_sum = 0;
    for(auto corner : two)
    {
        two_sum += corner->height;
    }
    float three_sum = 0;
    for(auto corner : three)
    {
        three_sum += corner->height;
    }
    float four_sum = 0;
    for(auto corner : four)
    {
        four_sum += corner->height;
    }
    median_height = (one_sum + 2*two_sum + 3*three_sum + 4*four_sum)/(4.0f * static_cast<float>(grid_cells.size()));
}

void Grid::solveDelta()
{
    for(auto& corner_line: grid_corners)
    {
        for(auto& corner: corner_line)
        {
            if(corner.on_edge)
            {
                corner.delta = median_height - corner.height;
            }
        }
    }
}

void Grid::solveGrid()
{
    solveCorners();
    solveMedian();
    solveDelta();
}

void Grid::createCells(std::array<int, 2> dims)
{
    grid_cells.clear();
    grid_cells.resize(dims[0]*dims[1], true);
}

void Grid::createCorners(std::array<int, 2> dims)
{
    if(dims[0]*dims[1] > 0)
    {
        grid_corners.resize(dims[1]+1);
        for(auto& corner : grid_corners)
        {
            corner.resize(dims[0]+1);
        }
    }
}

void Grid::updateCells(const std::vector<std::vector<bool>>& cells)
{
    int i = 0;
    for(auto& cell_line: cells)
    {
        for(auto cell: cell_line)
        {
            grid_cells[i] = cell;
            i++;
        }
    }
}

void Grid::updateCorners(const std::vector<std::vector<CornerInterface>>& corners)
{
    for(int y = 0; y < dimensions[1]; y++)
    {
        for(int x = 0; x < dimensions[0]; x++)
        {
            grid_corners[y][x].height = corners[y][x].getInputHeight();
        }
    }
}

void Grid::setDimensions(std::array<int, 2> new_dims)
{
    dimensions = new_dims;
    createCells(dimensions);
    createCorners(dimensions);
}

const std::vector<bool> &Grid::getCells()
{
    return grid_cells;
}

const std::vector<std::vector<Corner>> &Grid::getCorners()
{
    return grid_corners;
}

const std::array<int, 2> &Grid::getDimensions()
{
    return dimensions;
}

float Grid::getMedianHeight() const
{
    return median_height;
}



