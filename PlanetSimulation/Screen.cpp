#include "Screen.h"

// �����̬�����������ô��ڵķֱ��ʣ���Ϊһ���ص�����
static void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    // ������������Ӱ�����������FPS����������һ��ע�͵�
    std::cout << "solution = " << width << " * " << height << std::endl;
    glViewport(0, 0, width, height);
}

Screen::Screen(int width, int height, const char* title)
{
    this->width = width;
    this->height = height;
    this->deltaTime = 0.0f;
    this->lastFrameTime = 0.0f;
    // �Ȱѱ�����ɫ����Ϊ��
    this->bgRed = 0.0f;
    this->bgGreen = 0.0f;
    this->bgBlue = 0.0f;
    // ��ʼ��GLFW
    if (!glfwInit()) 
    {
        std::cerr << "GLFW init failed\n";
        std::exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // ��ʼ��GLFW�Ĵ���
    this->window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "GLFW window creation failed\n";
        glfwTerminate();
        std::exit(-1);
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, FramebufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        std::exit(-1);
    }
    glViewport(0, 0, width, height); 
}

bool Screen::ShouldClose() const {
    return glfwWindowShouldClose(window);
}

// ���ٴ���,�ͷ��ڴ���Դ
void Screen::Terminate()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Screen::SetBackGroundColor(float bgRed, float bgGreen, float bgBlue)
{
    this->bgRed = bgRed;
    this->bgGreen = bgGreen;
    this->bgBlue = bgBlue;
}


void Screen::updateWindowTitle()
{
    char title[256];
    float fps = static_cast<float>(frameCount);
    snprintf(title, sizeof(title), "Ez-Planet Engine - [FPS: %.0f]", fps);
    glfwSetWindowTitle(window, title);
}

GLFWwindow* Screen::GetGLFWwindow()
{
    return this->window;
}

// ������ʱ���̶����������ˢ���ʣ�������bug���ٹ̶�ˢ����
void Screen::Update()
{
    float currentTime = static_cast<float>(glfwGetTime());
    deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    frameCount++;
    double now = glfwGetTime();
    if (now - lastFPSTime >= 1.0) 
    {
        updateWindowTitle();  // ÿ��ˢ��һ��
        frameCount = 0;
        lastFPSTime = now;
    }

    glfwPollEvents(); // ���ڴ������¼�

}

// ÿһ֡����Ҫ�����µ�С����λ�ã�����������Ҫһ����������
void Screen::Clear()
{
    glClearColor(bgRed, bgGreen, bgBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// ����������Buffer������������OpenGL�����ˢ����Ļ��Ϊ
void Screen::SwapBuffers()
{
    glfwSwapBuffers(window);
}

Screen::~Screen()
{
    Terminate();
}