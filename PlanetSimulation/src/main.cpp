#include "Screen.h"
#include "Input.h"
#include "Camera2D.h"
#include "Rendered2D.h"

int main()
{

	Screen screen(800, 600, "Ez-Planet Engine");
    Camera2D camera(screen.GetWidth(), screen.GetHeight()); //创建摄像机类，用于后续的坐标轴放缩变换
    Input input(screen.GetGLFWwindow(), camera.GetCamera());//创建输入类，用于后续接受键盘鼠标的输入
    input.EventCallBackInit(); // 注册事件回调,与键盘鼠标输入有关
    Renderer2D renderer; // 创建渲染器类，用于后续坐标轴绘制，星球绘制等等
    // 主循环函数
    while (!screen.ShouldClose()) {
        screen.Update(); // 控制整个引擎FPS
        screen.Clear();

        camera.Update();

        renderer.DrawCoordinateAxis(20.0f);

        float t = glfwGetTime();  // 用时间演示动态变化
        float x = 0.5f * std::cos(t);
        float y = 0.5f * std::sin(t);
        
        screen.SetBackGroundColor(x, y, 0.0f);
        
        //// TODO: draw planets / orbit
        screen.SwapBuffers();
    }

	return 0;
}
