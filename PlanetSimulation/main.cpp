#include "Screen.h"
#include "Input.h"

int main()
{

	Screen screen(800, 600, "Ez-Planet Engine");
    Input input(screen.GetGLFWwindow());
    input.EventCallBackInit(); // ע���¼��ص�
    
    // ��ѭ������
    while (!screen.ShouldClose()) {
        screen.Update(); // ������������FPS


        // TODO: physics update(deltaTime)

        screen.Clear();
        float t = glfwGetTime();  // ��ʱ����ʾ��̬�仯
        float x = 0.5f * std::cos(t);
        float y = 0.5f * std::sin(t);
        
        screen.SetBackGroundColor(x, y, 0.0f);
        
        //// TODO: draw planets / orbit
        screen.SwapBuffers();
    }

	return 0;
}
