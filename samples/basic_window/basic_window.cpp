﻿// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#include <iostream>

#include "wt/glfw_wrapper.h"

int main()
{
    std::cout << "sample hello-window" << std::endl;

    auto window = ax::wt::window_t(640, 480, "Hello World");

    while (!window.should_close())
    {
        window.swap_buffers();
        window.poll_events();
    }

    return 0;
}