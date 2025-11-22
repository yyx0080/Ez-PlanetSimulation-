#pragma once
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"

class Camera2D
{
public:
    Camera2D(int width, int height);

    void SetScreenSize(int width, int height);

    void Zoom(double yoffset);
    void BeginDrag(double xpos, double ypos);
    void Drag(double xpos, double ypos);
    void EndDrag();

    void Reset();

    glm::mat4 GetViewMatrix() const { return viewMatrix; }
    glm::mat4 GetProjectionMatrix() const { return projection; }

    float GetZoom() const { return zoom; }
    void Update();

    Camera2D* GetCamera();
private:
    void UpdateViewMatrix();

private:
    float zoom;
    glm::vec2 offset; // 世界坐标偏移
    glm::mat4 viewMatrix;
    glm::mat4 projection;

    // 拖动相关
    bool dragging;
    double lastX, lastY;

    int screenW, screenH;
};
