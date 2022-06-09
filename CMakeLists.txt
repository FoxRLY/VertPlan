cmake_minimum_required(VERSION 3.20)

project(VertPlan)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message("Windows build")
    set(SFML_DIR "c:/SFML/lib/cmake/SFML")
    if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        set(CMAKE_CXX_FLAGS_RELEASE "-mwindows")
        set(CMAKE_CXX_FLAGS_RELEASE "-Og")
    endif()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Linux build")
    if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        set(CMAKE_CXX_FLAGS_RELEASE "-0g")
    endif()
endif()

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

add_executable(VertPlan main.cpp
        UIElements/UIElement.h UIElements/UIConstructor.cpp UIElements/UIConstructor.h UIElements/UIElement.cpp

        UIBodies/RectShapeBody.cpp UIBodies/RectShapeBody.h UIBodies/DrawingBody.cpp UIBodies/DrawingBody.h
        UIBodies/CameraBody.cpp UIBodies/CameraBody.h UIBodies/UIElementBody.cpp UIBodies/UIElementBody.h

        UIEvents/ButtonEvent.cpp UIEvents/ButtonEvent.h UIEvents/InputTextBoxEvent.cpp UIEvents/InputTextBoxEvent.h
        UIEvents/GraphNavEvent.cpp UIEvents/GraphNavEvent.h  UIEvents/DefaultEvent.cpp UIEvents/DefaultEvent.h
        UIEvents/UIEvent.cpp UIEvents/UIEvent.h UIBodies/GraphDrawingBody.cpp UIBodies/GraphDrawingBody.h
        translator.cpp translator.h Grid.cpp Grid.h InputTextBox.cpp InputTextBox.h GridInterface.cpp GridInterface.h CornerInterface.cpp CornerInterface.h)

target_link_libraries(VertPlan sfml-graphics sfml-audio sfml-window sfml-system)