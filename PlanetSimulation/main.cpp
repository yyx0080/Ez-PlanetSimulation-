#include "Screen.h"

int main()
{

	Screen screen(800, 600, "Ez-Planet Engine");

    // ��ѭ������
    while (!screen.ShouldClose()) {
        screen.Update(); // ������������FPS


        // TODO: physics update(deltaTime)

        screen.Clear();
        //// TODO: draw planets / orbit
        screen.SwapBuffers();
    }

	return 0;
}
