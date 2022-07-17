// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#include <iostream>

#include "Wt/GlfwWrapper.hpp"

int main()
{
    std::cout << "sample hello-window" << std::endl;

    constexpr int32_t width = 800;
    constexpr int32_t height = 480;

    const auto& window = ax::wt::Window(width, height, "Hello World");

    while (!window.ShouldClose())
    {
        window.SwapBuffers();
        window.PollEvents();


        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.07, 0.13, 0.17f, 1.0f);

        glBegin(GL_TRIANGLES);
        
        glVertex2f(-0.5F, 0.5F);
        glVertex2f(0.5F, 0.5F);
        glVertex2f(0.0F, -0.5F);

        glColor3f(0.0, 1.0, 1.0);
        
        glEnd();
    }

    window.Terminate();

    return 0;
}
