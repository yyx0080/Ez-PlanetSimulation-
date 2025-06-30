#include "Screen.h"

int main()
{

	Screen screen(800, 600, "Ez-Planet Engine");

    // 主循环函数
    while (!screen.ShouldClose()) {
        screen.Update(); // 控制整个引擎FPS


        // TODO: physics update(deltaTime)

        screen.Clear();
        //// TODO: draw planets / orbit
        screen.SwapBuffers();
    }

	return 0;
}
