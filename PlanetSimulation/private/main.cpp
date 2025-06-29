#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		//����������Ϊ�رգ�����ѭ��
		glfwSetWindowShouldClose(window, true);
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	//glfw��ʼ��
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//glfw��������
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		printf("��������ʧ��");
		//��ֹ
		glfwTerminate();
		return -1;
	}
	//��ʾ����
	glfwMakeContextCurrent(window);

	//���ûص��������ڴ�С�����󽫵��øûص�����
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad��ʼ��
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("����ʧ��");
		return -1;
	}

	// ʹ��ѭ���ﵽѭ����ȾЧ��
	while (!glfwWindowShouldClose(window))
	{
		//�Զ��������¼�
		processInput(window);
		//������������������ʾ�հ�
		glfwSwapBuffers(window);
		//��������¼�,�����޷��Դ��ڽ��н���
		glfwPollEvents();
	}

	//��ֹ��Ⱦ �رղ�����glfw������Դ
	glfwTerminate();
	return 0;
}
