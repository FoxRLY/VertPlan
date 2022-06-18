#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

static const char* alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

using namespace sf;
using FontPresetFunc = void(*)(Text&, Font&);

class Signs
{
private:

    RenderWindow* window;
    FontPresetFunc preset_func;
    Font& preset_font;
    std::vector<Text> horizontal_signs;
    std::vector<Text> vertical_signs;
    Vector2i dims;
    Vector2i pos;
    int cell_size;
public:
    Signs(RenderWindow* new_window, FontPresetFunc func, Font& font, Vector2i new_pos, Vector2i new_dims, int size);
    void setWindow(RenderWindow* new_window);
    void setCellSize(int new_size);
    void setDimensions(Vector2i new_dims);
    void setPos(Vector2i new_pos);
    static std::string intToCharSign(int number);
    void draw();
};

