#include "Camera2D.h"

Camera2D::Camera2D(int width,int height)
{
    this->zoom = 1.0f;
    this->offset = glm::vec2(0.0f, 0.0f);
    this->dragging = false;
    this->screenW = width;
    this->screenH = height;
    projection = glm::ortho(
        -screenW * 0.5f, screenW * 0.5f,
        -screenH * 0.5f, screenH * 0.5f,
        -1.0f, 1.0f
    );

    UpdateViewMatrix();
}

void Camera2D::SetScreenSize(int width, int height)
{
    screenW = width;
    screenH = height;

    projection = glm::ortho(
        -screenW * 0.5f, screenW * 0.5f,
        -screenH * 0.5f, screenH * 0.5f,
        -1.0f, 1.0f
    );
}

void Camera2D::Zoom(double yoffset)
{
    zoom *= (1.0f + yoffset * 0.1f);
    if (zoom < 0.1f) zoom = 0.1f;
    if (zoom > 20.0f) zoom = 20.0f;

    UpdateViewMatrix();
}

void Camera2D::BeginDrag(double xpos, double ypos)
{
    dragging = true;
    lastX = xpos;
    lastY = ypos;
}

void Camera2D::Drag(double xpos, double ypos)
{
    if (!dragging) return;

    double dx = xpos - lastX;
    double dy = ypos - lastY;

    offset.x += dx / zoom;
    offset.y -= dy / zoom;

    lastX = xpos;
    lastY = ypos;

    UpdateViewMatrix();
}

void Camera2D::EndDrag()
{
    dragging = false;
}

void Camera2D::Reset()
{
    zoom = 1.0f;
    offset = glm::vec2(0.0f);
    UpdateViewMatrix();
}

void Camera2D::UpdateViewMatrix()
{
    viewMatrix = glm::mat4(1.0f);
    viewMatrix = glm::translate(viewMatrix, glm::vec3(offset, 0.0f));
    viewMatrix = glm::scale(viewMatrix, glm::vec3(zoom, zoom, 1.0f));
}

void Camera2D::Update()
{
    UpdateViewMatrix();
}

Camera2D* Camera2D::GetCamera()
{
    return this;
}
