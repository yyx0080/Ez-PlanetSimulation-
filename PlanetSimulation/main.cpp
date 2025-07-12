#include "Screen.h"
#include "Input.h"

int main()
{

	Screen screen(800, 600, "Ez-Planet Engine");
    Input input(screen.GetGLFWwindow());
    input.EventCallBackInit(); // 注册事件回调
    
    // 主循环函数
    while (!screen.ShouldClose()) {
        screen.Update(); // 控制整个引擎FPS


        // TODO: physics update(deltaTime)

        screen.Clear();
        float t = glfwGetTime();  // 用时间演示动态变化
        float x = 0.5f * std::cos(t);
        float y = 0.5f * std::sin(t);
        
        screen.SetBackGroundColor(x, y, 0.0f);
        
        //// TODO: draw planets / orbit
        screen.SwapBuffers();
    }

	return 0;
}
