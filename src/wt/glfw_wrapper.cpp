// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#include <iostream>
#include "glfw_wrapper.h"
#include "../exception/window_creation_exception.h"
#include "../exception/glfw_initialization_exception.h"
#include "../service/glfw_error_humanizer_service.h"

ax::wt::window_t::window_t(int32_t width, int32_t height, std::string title)
    : width_(width), height_(height), title_(std::move(title))
{

    if (glfwInit() == GLFW_FALSE){
        auto error = ax::service::glfw_error_humanizer_service::get_human_readable_error();

        std::cout << "GLFW initialization failed: " << error << std::endl;
        throw ax::exception::glfw_initialization_exception("GLFW initialization failed");
    }

    auto window = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);

    if (window == nullptr)
    {
        auto error = ax::service::glfw_error_humanizer_service::get_human_readable_error();

        std::cout << "Window creation failed with error: " << error << std::endl;
        throw ax::exception::window_creation_exception(error);
    }

    glfwMakeContextCurrent(window);

    buffer_ = std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(window, &glfwDestroyWindow);
}