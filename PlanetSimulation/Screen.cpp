#include "Screen.h"

// 这个静态函数用于设置窗口的分辨率，作为一个回调函数
static void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    // 这里的输出可能影响整个引擎的FPS，所以这里一般注释掉
    std::cout << "solution = " << width << " * " << height << std::endl;
    glViewport(0, 0, width, height);
}

Screen::Screen(int width, int height, const char* title)
{
    this->width = width;
    this->height = height;
    this->deltaTime = 0.0f;
    this->lastFrameTime = 0.0f;
    // 先把背景颜色设置为黑
    this->bgRed = 0.0f;
    this->bgGreen = 0.0f;
    this->bgBlue = 0.0f;
    // 初始化GLFW
    if (!glfwInit()) 
    {
        std::cerr << "GLFW init failed\n";
        std::exit(-1);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 初始化GLFW的窗口
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

// 销毁窗口,释放内存资源
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

// 这里暂时不固定整个引擎的刷新率，后续出bug了再固定刷新率
void Screen::Update()
{
    float currentTime = static_cast<float>(glfwGetTime());
    deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    frameCount++;
    double now = glfwGetTime();
    if (now - lastFPSTime >= 1.0) 
    {
        updateWindowTitle();  // 每秒刷新一次
        frameCount = 0;
        lastFPSTime = now;
    }

    glfwPollEvents(); // 用于处理窗口事件

}

// 每一帧都需要绘制新的小行星位置，所以这里需要一个清屏函数
void Screen::Clear()
{
    glClearColor(bgRed, bgGreen, bgBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

// 将缓冲区的Buffer交换上来，是OpenGL经典的刷新屏幕行为
void Screen::SwapBuffers()
{
    glfwSwapBuffers(window);
}

Screen::~Screen()
{
    Terminate();
}