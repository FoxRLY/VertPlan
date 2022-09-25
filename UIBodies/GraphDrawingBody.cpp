#include "GraphDrawingBody.h"

GraphDrawingBody::GraphDrawingBody(std::shared_ptr<RenderWindow>& new_window) : DrawingBody(new_window)
{
    plane_size = 1;
    grid_size = 1;
    grid_range = 1;
}

void GraphDrawingBody::setFont(Font &new_font)
{
    font = new_font;
}

void GraphDrawingBody::setPlaneSize(int size)
{
    plane_size = size;
}

void GraphDrawingBody::setGridSize(int size)
{
    grid_size = size;
}

void GraphDrawingBody::setGridRange(float range)
{
    grid_range = range;
}

void GraphDrawingBody::drawGraphPlane()
{
    //drawRect(Color::White, Color::White, Vector2f(0,0), Vector2f(plane_size, plane_size), 0);
    float grid_aspect = grid_size / grid_range;
    for(int i = 0; i < plane_size; i += grid_size)
    {
        if(plane_size / 2.0 == (float)i)
        {
            this->drawHorLine(Color::Green, i, 3);
            this->drawVertLine(Color::Red, i, 3);
        }
        else
        {
            this->drawHorLine(Color::Black, i, 2);
            this->drawVertLine(Color::Black, i, 2);
        }

        for(int k = 0; k < plane_size; k += grid_size)
        {
            Text number;
            number.setFont(font);
            number.setString("");
            number.setFillColor(Color::Black);
            number.setCharacterSize(12);
            std::string y_number = std::to_string(-(i - plane_size/2) / grid_aspect);
            std::string x_number = std::to_string((k - plane_size/2) / grid_aspect);
            for(int z = 0; z < y_number.length(); z++)
            {
                if(y_number[z] == '.')
                {
                    while(y_number.length() > z+3)
                    {
                        y_number.pop_back();
                    }
                }
            }
            for(int z = 0; z < x_number.length(); z++)
            {
                if(x_number[z] == '.')
                {
                    while(x_number.length() > z+3)
                    {
                        x_number.pop_back();
                    }
                }
            }

            number.setString(x_number);
            number.setOrigin(number.getGlobalBounds().width, 0);
            this->drawText(number, Vector2f(k-3, i+3));

            number.setString(y_number);
            number.setOrigin(0, number.getGlobalBounds().height);
            this->drawText(number, Vector2f(k+3,i-3));
        }
    }
}

void GraphDrawingBody::drawGraphFunc(std::vector<double>& results, Color line_color)
{
    int point_count = results.size();
    double step = (float)plane_size / (float)point_count;

    int index = 0;
    for(double x = 0; x <= plane_size-step; x += step)
    {
        double y = results[index];
        y = ((y / grid_range) * grid_size * -1) + ((double)plane_size / 2);
        double y_next = results[index+1];
        y_next = ((y_next / grid_range) * grid_size * -1) + ((double)plane_size / 2);
        double x_next = x + step;
        drawLine(line_color, Vector2f(x+(step/2), y), Vector2f(x_next+(step/2), y_next), 5);
        index++;
    }
}
