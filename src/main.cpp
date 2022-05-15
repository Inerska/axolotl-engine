#include "wt/glfw_wrapper.h"

int main()
{
    ax::wt::window_t window = ax::wt::window_t(640, 480, "Hello World");

    while (!window.should_close())
    {
        window.swap_buffers();
        glfwPollEvents();
    }

    return 0;
}