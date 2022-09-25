#include "CameraBody.h"


CameraBody::CameraBody(std::shared_ptr<RenderWindow>& new_window) : UIElementBody(new_window)
{
    auto window_ptr = window.lock();
    if(window_ptr)
    {
        default_view = window_ptr->getDefaultView();
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }
}

void CameraBody::setDefaultView(View new_view)
{
    default_view = new_view;
}

View CameraBody::getDefaultView()
{
    return default_view;
}

void CameraBody::applyView()
{

    auto window_ptr = window.lock();
    if(window_ptr)
    {
        window_ptr->setView(view);
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }
}

void CameraBody::resetView()
{
    auto window_ptr = window.lock();
    if(window_ptr)
    {
        window_ptr->setView(default_view);
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }
}

[[maybe_unused]] RectangleShape CameraBody::shapeToView(View &new_view)
{
    RectangleShape new_shape;
    auto window_ptr = window.lock();
    if(window_ptr)
    {
        Vector2f size(new_view.getViewport().width*(float)window_ptr->getSize().x,
                      new_view.getViewport().height*(float)window_ptr->getSize().y);
        Vector2f pos(new_view.getViewport().left*(float)window_ptr->getSize().x,
                     new_view.getViewport().top*(float)window_ptr->getSize().y);
        new_shape.setSize(size);
        new_shape.setPosition(pos);
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }
    return new_shape;
}
View CameraBody::viewToShape(RectangleShape& new_shape)
{
    View new_view;
    auto window_ptr = window.lock();
    if(window_ptr)
    {
        FloatRect rect;
        rect.width = new_shape.getSize().x / (float)window_ptr->getSize().x;
        rect.height = new_shape.getSize().y / (float)window_ptr->getSize().y;
        rect.left = new_shape.getPosition().x / (float)window_ptr->getSize().x;
        rect.top = new_shape.getPosition().y / (float)window_ptr->getSize().y;
        new_view.setViewport(rect);
    }
    else
    {
        throw std::runtime_error("No window to draw on");
    }
    return new_view;
}
Vector2f CameraBody::rectPosToViewPos(Vector2f pos)
{
    return {pos.x + shape.getSize().x/2.0f,pos.y + shape.getSize().y/2.0f};
}
Vector2f CameraBody::viewPosToRectPos(Vector2f pos)
{
    return {pos.x - shape.getSize().x/2.0f,pos.y - shape.getSize().y/2.0f};
}

void CameraBody::setDisplayRect(Vector2f pos, Vector2f size)
{
    shape.setPosition(pos);
    shape.setSize(size);
    view = viewToShape(shape);
}

[[maybe_unused]] View CameraBody::getView()
{
    return view;
}

[[maybe_unused]] void CameraBody::setZoom(float factor)
{
    view.zoom(factor);
}

void CameraBody::setViewSize(Vector2f size)
{
    view.setSize(size);
}

void CameraBody::setCameraPos(Vector2f pos)
{
    view.setCenter(rectPosToViewPos(pos));
}

[[maybe_unused]] void CameraBody::setCameraCenter(Vector2f pos)
{
    view.setCenter(pos);
}

Vector2f CameraBody::getCameraPos()
{
    return viewPosToRectPos(view.getCenter());
}

bool CameraBody::mouseHover(Vector2f mouse_pos)
{
    return shape.getGlobalBounds().contains(mouse_pos);
}
FloatRect CameraBody::getGlobalBounds()
{
    return shape.getGlobalBounds();
}
FloatRect CameraBody::getLocalBounds()
{
    return shape.getLocalBounds();
}
void CameraBody::transform(Vector2f pos, Vector2f size)
{
    setDisplayRect(pos, size);
}
void CameraBody::draw()
{
}