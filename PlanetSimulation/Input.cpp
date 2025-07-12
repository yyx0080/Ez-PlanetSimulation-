#include "Input.h"



Input::Input(GLFWwindow* win)
{
	this->window = win;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << "左键按下，坐标: (" << xpos << ", " << ypos << ")" << std::endl;
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        std::cout << "右键按下" << std::endl;
    }
    // 这里应该要把坐标传送给Planet这个类，用于生成一个星球
    // 所以这个static函数需要调用Planet类中的赋值方法给xy
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        std::cout << "键被按下: " << key << std::endl;
    }
    else if (action == GLFW_RELEASE)
    {
        std::cout << "键被松开: " << key << std::endl;
    }
}

void Input::EventCallBackInit()
{
    // 注册事件回调
    glfwSetKeyCallback(this->window, key_callback);
    glfwSetMouseButtonCallback(this->window, mouse_button_callback);
    /*glfwSetCursorPosCallback(this->window, mouse_move_callback);*/
}
