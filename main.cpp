#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "UIElements/UIConstructor.h"

using namespace sf;

void TextPreset(Text& text, Font& font)
{
    text.setFont(font);
    text.setString("");
    text.setFillColor(Color::Black);
    text.setCharacterSize(25);
}

class InputTextBox
{
private:
    UIElement *text_box;
    Text text;
public:
    static void userInputHandle(std::vector<InputTextBox *> &input_box_list, char input_char) {
        for (auto input_box: input_box_list) {
            if (InputTextBoxEvent::inputChar(input_box->text_box, input_box->text, input_char)) {
                break;
            }
        }
    }

    explicit InputTextBox(RenderWindow *window) {
        text_box = UIConstructor::createRectShapeInputTextBox(window);
        text.setString("");
    }

    void setString(const char *new_str) {
        text.setString(new_str);
    }

    void setPreset(void(*preset_func)(Text &, Font &), Font &font) {
        preset_func(text, font);
    }

    void setTextPos(Vector2f pos) {
        text.setPosition(pos);
    }

    void setTextPos(float x, float y) {
        text.setPosition(x, y);
    }

    void setInputBoxPos(Vector2f pos) {
        text_box->getBody()->transform(pos, Vector2f(text_box->getBody()->getGlobalBounds().width,
                                                     text_box->getBody()->getGlobalBounds().height));
    }

    void setInputBoxPos(float x, float y) {
        text_box->getBody()->transform(Vector2f(x, y), Vector2f(text_box->getBody()->getGlobalBounds().width,
                                                                text_box->getBody()->getGlobalBounds().height));
    }

    UIElement* getUIElement()
    {
        return text_box;
    }

    Text& getText()
    {
        return text;
    }

    void transformInputBox(Vector2f pos, Vector2f size)
    {
        text_box->getBody()->transform(pos, size);
    }

    void drawText()
    {
        text_box->getBody()->getWindow()->draw(text);
    }

    void drawTextBox()
    {
        text_box->draw();
    }
};

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 8.0;

    // Окно приложения
    VideoMode videoMode = VideoMode::getDesktopMode();
    videoMode.width = videoMode.width/1.2f;
    videoMode.height = videoMode.height/1.2;
    RenderWindow window(videoMode, L"Вертикальная планировка", Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    // Шрифт для элементов
    Font mono;
    mono.loadFromFile("../assets/JetBrainsMono-Bold.ttf");

    // Список элементов интерфейса
    std::vector<UIElement*> main_element_list;
    std::vector<UIElement*> grid_element_list;
    std::vector<InputTextBox*> text_box_list;

    // Камера
    UIElement* camera = UIConstructor::createCameraBox(&window);
    {
        auto camera_body = (CameraBody*)camera->getBody();
        camera_body->setDisplayRect(Vector2f(0,48), Vector2f((float)videoMode.width, (float)videoMode.height));
        camera_body->setViewSize(window.getView().getSize());
        camera_body->setCameraPos(Vector2f(0, 0));
        main_element_list.push_back(camera);
    }
    float camera_zoom = 1.0f;

    // Галка "Редактировать"
    UIElement* redact_check_box = UIConstructor::createRectShapeCheckBox(&window);
    {
        auto body = (RectShapeBody*)redact_check_box->getBody();
        body->transform(Vector2f(1050, 5), Vector2f(30, 30));
        RectShapeBodyPreset(body);
        main_element_list.push_back(redact_check_box);
    }

    //Кнопка
    UIElement* square_1 = UIConstructor::createRectShapeCheckBox(&window);
    {
        auto button_body = (RectShapeBody*)square_1->getBody();
        button_body->transform(Vector2f(0, 0), Vector2f(100, 100));
        RectShapeBodyPresetGrid(button_body);
        grid_element_list.push_back(square_1);
    }

    UIElement* square_2 = UIConstructor::createRectShapeCheckBox(&window);
    {
        auto button_body = (RectShapeBody*)square_2->getBody();
        button_body->transform(Vector2f(0, 103), Vector2f(100, 100));
        RectShapeBodyPresetGrid(button_body);
        grid_element_list.push_back(square_2);
    }

    UIElement* square_3 = UIConstructor::createRectShapeCheckBox(&window);
    {
        auto button_body = (RectShapeBody*)square_3->getBody();
        button_body->transform(Vector2f(103, 0), Vector2f(100, 100));
        RectShapeBodyPresetGrid(button_body);
        grid_element_list.push_back(square_3);
    }

    UIElement* square_4 = UIConstructor::createRectShapeCheckBox(&window);
    {
        auto button_body = (RectShapeBody*)square_4->getBody();
        button_body->transform(Vector2f(103, 103), Vector2f(100, 100));
        RectShapeBodyPresetGrid(button_body);
        grid_element_list.push_back(square_4);
    }

    // Подпись к вводу сетки
    Text grid_size_label;
    {
        TextPreset(grid_size_label, mono);
        grid_size_label.setString(L"Размер сетки:");
        grid_size_label.setPosition(5, 5);
    }

    // Знак Икс
    Text grid_size_sign_label;
    {
        TextPreset(grid_size_sign_label, mono);
        grid_size_sign_label.setString(L"X");
        grid_size_sign_label.setPosition(283, 5);
    }

    // Подпись к вводу размера квадрата
    Text grid_square_size_label;
    {
        TextPreset(grid_square_size_label, mono);
        grid_square_size_label.setString(L"Размер квадрата:");
        grid_square_size_label.setPosition(400, 5);
    }

    // Подпись "Редактировать сетку"
    Text grid_redact_label;
    {
        TextPreset(grid_redact_label, mono);
        grid_redact_label.setString(L"Редактировать сетку:");
        grid_redact_label.setPosition(740, 5);
    }

    // Кол-во клеток по горизонтали
    InputTextBox grid_x_input(&window);
    {
        grid_x_input.setString("");
        grid_x_input.setTextPos(212, 5);
        grid_x_input.setPreset(TextPreset, mono);
        grid_x_input.transformInputBox(Vector2f(210, 5), Vector2f(60, 30));
        main_element_list.push_back(grid_x_input.getUIElement());
        text_box_list.push_back(&grid_x_input);
    }

    // Кол-во клеток по горизонтали
    InputTextBox grid_y_input(&window);
    {
        grid_y_input.setString("");
        grid_y_input.setTextPos(312, 5);
        grid_y_input.setPreset(TextPreset, mono);
        grid_y_input.transformInputBox(Vector2f(310, 5), Vector2f(60, 30));
        main_element_list.push_back(grid_y_input.getUIElement());
        text_box_list.push_back(&grid_y_input);
    }

    // Размер квадратов
    InputTextBox grid_square_input(&window);
    {
        grid_square_input.setString("");
        grid_square_input.setTextPos(Vector2f(650, 5));
        grid_square_input.setPreset(TextPreset, mono);
        grid_square_input.transformInputBox(Vector2f(650, 5), Vector2f(60, 30));
        main_element_list.push_back(grid_square_input.getUIElement());
        text_box_list.push_back(&grid_square_input);
    }

    // Края карты
    RectangleShape map_edge;
    {
        map_edge.setSize(Vector2f(videoMode.width, videoMode.height));
        map_edge.setPosition(Vector2f(0, 48));
        map_edge.setOutlineThickness(1);
        map_edge.setOutlineColor(Color::Black);
    }

    // Края ввода размеров сетки
    RectangleShape grid_size_input_edge;
    {
        grid_size_input_edge.setSize(Vector2f(390, 48));
        grid_size_input_edge.setPosition(Vector2f(0, 0));
        grid_size_input_edge.setOutlineThickness(1);
        grid_size_input_edge.setOutlineColor(Color::Black);
    }

    RectangleShape grid_square_input_edge;
    {
        grid_square_input_edge.setSize(Vector2f(730, 48));
        grid_square_input_edge.setPosition(Vector2f(0, 0));
        grid_square_input_edge.setOutlineThickness(1);
        grid_square_input_edge.setOutlineColor(Color::Black);
    }
    // Цикл приложения
    while(window.isOpen())
    {
        auto camera_body = (CameraBody*)camera->getBody();
        UIElement::eventCheckLoop(main_element_list);
        camera_body->applyView();
        UIElement::eventCheckLoop(grid_element_list);
        camera_body->resetView();

        // Перемещение камеры
        auto* camera_box_event = (GraphNavEvent*)camera->getEvent();
        camera_body->setCameraPos(camera_body->getCameraPos() - camera_box_event->getMouseDelta() * camera_zoom);

        // Цикл обработки событий окна
        Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case Event::Closed:
                {
                    window.close();
                    break;
                }
                // Система зума
                case Event::MouseWheelScrolled:
                {
                    float delta = event.mouseWheelScroll.delta;
                    float camera_zoom_prev = camera_zoom;
                    camera_zoom -= delta*0.1f;
                    if(camera_zoom <= 0 || camera_zoom >= 2)
                    {
                        camera_zoom = camera_zoom_prev;
                    }
                    camera_body->setViewSize(window.getDefaultView().getSize()*camera_zoom);
                    break;
                }
                case Event::TextEntered:
                {
                    if(event.text.unicode < 128)
                    {
                        char input_char = static_cast<char>(event.text.unicode);
                        InputTextBox::userInputHandle(text_box_list, input_char);
                    }
                    break;
                }
            }
        }

        if(redact_check_box->getEventResult())
        {
            square_1->setEventEnabled(true);
            square_2->setEventEnabled(true);
            square_3->setEventEnabled(true);
            square_4->setEventEnabled(true);
        }
        else
        {
            square_1->setEventEnabled(false);
            square_2->setEventEnabled(false);
            square_3->setEventEnabled(false);
            square_4->setEventEnabled(false);
        }

        // Фаза отрисовки элементов
        window.clear(Color::White);

        window.draw(grid_square_input_edge);
        window.draw(grid_size_input_edge);
        window.draw(map_edge);

        camera_body->applyView();
        square_1->draw();
        square_2->draw();
        square_3->draw();
        square_4->draw();
        camera_body->resetView();

        redact_check_box->draw();
        grid_x_input.drawTextBox();
        grid_y_input.drawTextBox();
        grid_square_input.drawTextBox();
        grid_y_input.drawText();
        grid_x_input.drawText();
        grid_square_input.drawText();
        window.draw(grid_size_label);
        window.draw(grid_size_sign_label);
        window.draw(grid_square_size_label);
        window.draw(grid_redact_label);

        // Вывод изображения
        window.display();
    }
}
