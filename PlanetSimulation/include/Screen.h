#pragma once
#include <glad/glad.h> // 必须最先包含！
#include <GLFW/glfw3.h> // glad 后面再包含 glfw
#include <iostream>
#include <string>

class Screen {
public:
    Screen(int width, int height, const char* title);
    ~Screen();

    bool ShouldClose() const;
    void Update();              // 处理事件 + 计算 deltaTime
    void Clear();               // 清屏
    void SwapBuffers();         // 刷新屏幕
    void Terminate();           // 销毁窗口
    void SetBackGroundColor(float bgRed, float bgGreen, float bgBlue); // 改变背景颜色的接口
    void GetWindow();

    void updateWindowTitle();  // 输出帧率到标题上
    float GetDeltaTime() const; // 每帧时间差
    GLFWwindow* GetGLFWwindow();    // 访问原始窗口指针
    int GetWidth();
    int GetHeight();

private:
    GLFWwindow* window;
    int width, height;
    float lastFrameTime;
    float deltaTime;
    float bgRed, bgGreen, bgBlue;
    int frameCount = 0;
    double lastFPSTime = 0.0;
};