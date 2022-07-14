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
        glClearColor(1.f, 0.0f, 0.0f, 1.0f);
    }

    window.Terminate();

    return 0;
}