#pragma once
#include <array>
#include <vector>
#include "CornerInterface.h"

struct Corner
{
    int on_edge;
    float height;
    float delta;
};

class Grid
{
private:
    std::array<int, 2> dimensions;
    std::vector<bool> grid_cells;
    std::vector<std::vector<Corner>> grid_corners;
    std::vector<const Corner*> one;
    std::vector<const Corner*> two;
    std::vector<const Corner*> three;
    std::vector<const Corner*> four;
    float median_height;
    float cell_size;

    void createCells(std::array<int,2> dims);
    void createCorners(std::array<int,2> dims);
    void solveCorners();
    void solveMedian();
    void solveDelta();
public:
    Grid(): dimensions{0}
    {
        median_height = 0;
        cell_size = 0;
    }
    explicit Grid(std::array<int,2> new_dims): Grid()
    {
        setDimensions(new_dims);
    }
    void setDimensions(std::array<int,2> new_dims);
    const std::array<int, 2>& getDimensions();
    void updateCells(const std::vector<std::vector<bool>>& cells);
    void updateCorners(const std::vector<std::vector<float>>& corners);
    void setCellSize(float new_size);
    float getCellSize() const;
    const std::vector<bool>& getCells();
    const std::vector<std::vector<Corner>>& getCorners();
    void solveGrid();
    float getMedianHeight() const;
};