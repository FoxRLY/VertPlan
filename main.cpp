#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "UIElements/UIConstructor.h"
#include "InputTextBox.h"
#include "GridAssets/GridInterface.h"

using namespace sf;

void TextPreset(Text& text, Font& font)
{
    text.setFont(font);
    text.setString("");
    text.setFillColor(Color::Black);
    text.setCharacterSize(25);
}

void TextPresetGrid(Text& text, Font& font)
{
    text.setFont(font);
    text.setString("");
    text.setFillColor(Color::Black);
    text.setCharacterSize(20);
}

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

    GridInterface grid(300, 10, {4,4}, &window, TextPresetGrid, mono);
    grid.setDimensions({3,3});
    // Камера
    UIElement* camera = UIConstructor::createCameraBox(&window);
    {
        auto camera_body = (CameraBody*)camera->getBody();
        camera_body->setDisplayRect(Vector2f(0,50), Vector2f((float)videoMode.width, (float)videoMode.height));
        camera_body->setViewSize(window.getView().getSize());
        camera_body->setCameraPos(Vector2f(0, 0));
        main_element_list.push_back(camera);
    }
    float camera_zoom = 1.0f;

    // Галка "Редактировать"
    bool prev_redact_flag = false;
    UIElement* redact_check_box = UIConstructor::createRectShapeCheckBox(&window);
    {
        auto body = (RectShapeBody*)redact_check_box->getBody();
        body->transform(Vector2f(1050, 10), Vector2f(30, 30));
        redact_check_box->setEventResult(true);
        RectShapeBodyPreset(body);
        main_element_list.push_back(redact_check_box);
    }

    UIElement* solve_button = UIConstructor::createRectShapeButton(&window);
    {
        auto body = (RectShapeBody*)solve_button->getBody();
        body->transform({1100,10},{30,30});
        RectShapeBodyPreset(body);
        main_element_list.push_back(solve_button);
    }

    // Подпись к вводу сетки
    Text grid_size_label;
    {
        TextPreset(grid_size_label, mono);
        grid_size_label.setString(L"Размер сетки:");
        grid_size_label.setPosition(5, 10);
    }

    // Знак Икс
    Text grid_size_sign_label;
    {
        TextPreset(grid_size_sign_label, mono);
        grid_size_sign_label.setString(L"X");
        grid_size_sign_label.setPosition(283, 10);
    }

    // Подпись к вводу размера квадрата
    Text grid_square_size_label;
    {
        TextPreset(grid_square_size_label, mono);
        grid_square_size_label.setString(L"Размер квадрата:");
        grid_square_size_label.setPosition(400, 10);
    }

    // Подпись "Редактировать сетку"
    Text grid_redact_label;
    {
        TextPreset(grid_redact_label, mono);
        grid_redact_label.setString(L"Редактировать сетку:");
        grid_redact_label.setPosition(740, 10);
    }

// Кол-во клеток по горизонтали
    InputTextBox grid_x_input(&window);
    {
        grid_x_input.setTextPos(212, 10);
        grid_x_input.setPreset(TextPreset, mono);
        grid_x_input.setString("4");
        grid_x_input.transformInputBox(Vector2f(210, 10), Vector2f(60, 30));
        main_element_list.push_back(grid_x_input.getUIElement());
        text_box_list.push_back(&grid_x_input);
    }

    // Кол-во клеток по горизонтали
    InputTextBox grid_y_input(&window);
    {
        grid_y_input.setPreset(TextPreset, mono);
        grid_y_input.setString("4");
        grid_y_input.setTextPos(312, 10);
        grid_y_input.transformInputBox(Vector2f(310, 10), Vector2f(60, 30));
        main_element_list.push_back(grid_y_input.getUIElement());
        text_box_list.push_back(&grid_y_input);
    }

    // Размер квадратов
    InputTextBox grid_square_input(&window);
    {
        grid_square_input.setPreset(TextPreset, mono);
        grid_square_input.setString("10");
        grid_square_input.setTextPos(Vector2f(650, 10));
        grid_square_input.transformInputBox(Vector2f(650, 10), Vector2f(60, 30));
        main_element_list.push_back(grid_square_input.getUIElement());
        text_box_list.push_back(&grid_square_input);
    }

    // Края карты
    RectangleShape map_edge;
    {
        map_edge.setSize(Vector2f(videoMode.width, videoMode.height));
        map_edge.setPosition(Vector2f(0, 50));
        map_edge.setOutlineThickness(1);
        map_edge.setOutlineColor(Color::Black);
    }

    // Края ввода размеров сетки
    RectangleShape grid_size_input_edge;
    {
        grid_size_input_edge.setSize(Vector2f(390, 50));
        grid_size_input_edge.setPosition(Vector2f(0, 0));
        grid_size_input_edge.setOutlineThickness(1);
        grid_size_input_edge.setOutlineColor(Color::Black);
    }

    RectangleShape grid_square_input_edge;
    {
        grid_square_input_edge.setSize(Vector2f(730, 50));
        grid_square_input_edge.setPosition(Vector2f(0, 0));
        grid_square_input_edge.setOutlineThickness(1);
        grid_square_input_edge.setOutlineColor(Color::Black);
    }

    // Флаг фокуса окна
    bool has_focus = true;
    // Цикл приложения
    while(window.isOpen())
    {
        auto camera_body = (CameraBody*)camera->getBody();
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
                        grid.inputEventCheck(input_char);
                    }
                    break;
                }
                case Event::MouseButtonPressed:
                {
                    if(event.mouseButton.button == Mouse::Right)
                    {
                        camera_body->setCameraPos({0,0});
                    }
                    break;
                }
                case Event::GainedFocus:
                {
                    has_focus = true;
                    break;
                }
                case Event::LostFocus:
                {
                    has_focus = false;
                    break;
                }
            }
        }

        if(has_focus)
        {
            UIElement::eventCheckLoop(main_element_list);
            camera_body->applyView();
            UIElement::eventCheckLoop(grid_element_list);
            grid.eventCheck();
            camera_body->resetView();

            // Перемещение камеры
            auto* camera_box_event = (GraphNavEvent*)camera->getEvent();
            camera_body->setCameraPos(camera_body->getCameraPos() - camera_box_event->getMouseDelta() * camera_zoom);
        }

        if(prev_redact_flag && !redact_check_box->getEventResult())
        {
            grid.setCellsActive(false);
            grid.updateGridStructure();
        }
        if(!prev_redact_flag && redact_check_box->getEventResult())
        {
            grid.setCellsActive(true);
            grid.hideCorners();
        }
        prev_redact_flag = redact_check_box->getEventResult();
        if(!prev_redact_flag && solve_button->getEventResult())
        {
            grid.solveGrid();
        }


        // Фаза отрисовки элементов
        window.clear(Color::White);

        window.draw(grid_square_input_edge);
        window.draw(grid_size_input_edge);
        window.draw(map_edge);

        camera_body->applyView();
        grid.draw();
        camera_body->resetView();

        redact_check_box->draw();
        solve_button->draw();
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
