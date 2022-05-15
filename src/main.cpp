#include "wt/glfw_wrapper.h"

int main()
{
    using namespace ax::wt;

    window_t window = window_t(640, 480, "Hello World");

    while (!window.should_close())
    {
        window.swap_buffers();
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}