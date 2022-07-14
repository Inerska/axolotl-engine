// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_WRAPPER_H
#define _GLFW_WRAPPER_H

#include <memory>
#include <string>

#include "Service/GLfwErrorHumanizerService.hpp"

#include "Exception/GlfwInitializationException.hpp"
#include "Exception/WindowCreationException.hpp"

#include "GlfwConfigCook.hpp"

namespace ax::wt
{
    class Window
    {
        std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> buffer_{nullptr, nullptr};
        int32_t width_{0};
        int32_t height_{0};
        std::string title_{"Axolotl Engine"};

    public:
        Window() noexcept
        = default;

        Window(const int32_t width, const int32_t height, std::string title) : width_(width), height_(height),
                                                                               title_(std::move(title))
        {
            if (glfwInit() == GLFW_FALSE)
            {
                const auto error = service::GLfwErrorHumanizerService::GetError();

                std::cout << "GLFW initialization failed: " << error << std::endl;

                throw exception::GlfwInitializationException("GLFW initialization failed");
            }

            auto *window = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);

            if (window == nullptr)
            {
                const auto error = service::GLfwErrorHumanizerService::GetError();

                std::cout << "Window creation failed with error: " << error << std::endl;
                throw exception::WindowCreationException(error);
            }

            glfwMakeContextCurrent(window);

            buffer_ = std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(window, &glfwDestroyWindow);
        }

        [[nodiscard]] bool ShouldClose() const
        {
            return static_cast<bool>(glfwWindowShouldClose(buffer_.get()));
        }

        void SwapBuffers() const
        {
            glfwSwapBuffers(buffer_.get());
        }

        void PollEvents() const
        {
            glfwPollEvents();
        }
    };
} // namespace ax::wt
#endif //_GLFW_WRAPPER_H
