#pragma once
#include <glad/glad.h> // �������Ȱ�����
#include <GLFW/glfw3.h> // glad �����ٰ��� glfw
#include <iostream>
#include <string>

class Screen {
public:
    Screen(int width, int height, const char* title);
    ~Screen();

    bool ShouldClose() const;
    void Update();              // �����¼� + ���� deltaTime
    void Clear();               // ����
    void SwapBuffers();         // ˢ����Ļ
    void Terminate();           // ���ٴ���
    void SetBackGroundColor(float bgRed, float bgGreen, float bgBlue); // �ı䱳����ɫ�Ľӿ�
    void GetWindow();

    void updateWindowTitle();  // ���֡�ʵ�������
    float GetDeltaTime() const; // ÿ֡ʱ���
    GLFWwindow* GetGLFWwindow();    // ����ԭʼ����ָ��

private:
    GLFWwindow* window;
    int width, height;
    float lastFrameTime;
    float deltaTime;
    float bgRed, bgGreen, bgBlue;
    int frameCount = 0;
    double lastFPSTime = 0.0;
};