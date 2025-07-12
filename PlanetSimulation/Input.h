#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

// 回调函数列表，用于获取输入事件，回调函数必须是一个static的静态函数才行
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

class Input
{
public:
	Input(GLFWwindow* win);
    
	// 注册事件回调
	void EventCallBackInit();

private:
	GLFWwindow* window; // 有Screen中获取

};
