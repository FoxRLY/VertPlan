#pragma once
#include "DrawingBody.h"


class GraphDrawingBody : public DrawingBody
{
private:
    int plane_size;
    int grid_size;
    float grid_range;
    Font font;
public:
    explicit GraphDrawingBody(RenderWindow* new_window);
    void setFont(Font& new_font);
    void setPlaneSize(int size);
    void setGridSize(int size);
    void setGridRange(float range);
    void drawGraphFunc(std::vector<double>& results, Color line_color);
    void drawGraphPlane();
};

