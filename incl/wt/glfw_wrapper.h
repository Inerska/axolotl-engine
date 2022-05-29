// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_WRAPPER_H
#define _GLFW_WRAPPER_H

#include <memory>
#include <string>

#include "service/glfw_error_humanizer_service.h"

#include "exception/glfw_initialization_exception.h"
#include "exception/window_creation_exception.h"

#include "glfw_config_cook.h"

namespace ax::wt
{
    class window_t
    {
    private:
        std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> buffer_{nullptr, nullptr};
        int32_t width_{0};
        int32_t height_{0};
        std::string title_{"Axolotl Engine"};

    public:

        inline window_t() noexcept: buffer_(nullptr, nullptr)
        {}

        inline window_t(int32_t width, int32_t height, std::string title) : width_(width), height_(height),
                                                                            title_(std::move(title))
        {
            if (glfwInit() == GLFW_FALSE)
            {
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

        [[nodiscard]] inline bool should_close() const
        {
            return glfwWindowShouldClose(buffer_.get());
        }

        inline void swap_buffers()
        {
            glfwSwapBuffers(buffer_.get());
        }

        inline void poll_events()
        {
            glfwPollEvents();
        }
    };
} // namespace ax::wt
#endif //_GLFW_WRAPPER_H