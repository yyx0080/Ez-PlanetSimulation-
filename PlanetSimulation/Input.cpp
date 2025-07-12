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
        std::cout << "������£�����: (" << xpos << ", " << ypos << ")" << std::endl;
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        std::cout << "�Ҽ�����" << std::endl;
    }
    // ����Ӧ��Ҫ�����괫�͸�Planet����࣬��������һ������
    // �������static������Ҫ����Planet���еĸ�ֵ������xy
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        std::cout << "��������: " << key << std::endl;
    }
    else if (action == GLFW_RELEASE)
    {
        std::cout << "�����ɿ�: " << key << std::endl;
    }
}

void Input::EventCallBackInit()
{
    // ע���¼��ص�
    glfwSetKeyCallback(this->window, key_callback);
    glfwSetMouseButtonCallback(this->window, mouse_button_callback);
    /*glfwSetCursorPosCallback(this->window, mouse_move_callback);*/
}
