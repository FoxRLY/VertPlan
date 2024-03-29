cmake_minimum_required(VERSION 3.20)
project(VertPlan)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message("Windows build")
    set(SFML_DIR "SFML/lib/cmake/SFML")
    if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        message("Release build")
        set(CMAKE_CXX_FLAGS_RELEASE "-mwindows -O3")
    endif()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Linux build")
    if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
        message("Release build")
        set(CMAKE_CXX_FLAGS_RELEASE "-O3")
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

        GridAssets/Grid.cpp GridAssets/Grid.h GridAssets/InputTextBox.cpp GridAssets/InputTextBox.h GridAssets/CornerInterface.cpp
        GridAssets/CornerInterface.h GridAssets/Corners.cpp GridAssets/Corners.h GridAssets/GridInterface.cpp
        GridAssets/GridInterface.h GridAssets/Cells.cpp GridAssets/Cells.h GridAssets/Signs.cpp GridAssets/Signs.h)

target_link_libraries(VertPlan sfml-graphics sfml-audio sfml-window sfml-system)