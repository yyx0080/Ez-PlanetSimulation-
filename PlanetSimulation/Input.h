#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

// �ص������б����ڻ�ȡ�����¼����ص�����������һ��static�ľ�̬��������
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class Input
{
public:
	Input(GLFWwindow* win);
    
	// ע���¼��ص�
	void EventCallBackInit();

private:
	GLFWwindow* window; // ��Screen�л�ȡ

};
