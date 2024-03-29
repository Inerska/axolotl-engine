﻿// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_WRAPPER_H
#define _GLFW_WRAPPER_H

#include <memory>
#include <string>
#include <glm/vec3.hpp>

#include "ApplicationContext.hpp"
#include "Service/GLfwErrorHumanizerService.hpp"

#include "Exception/GlfwInitializationException.hpp"
#include "Exception/WindowCreationException.hpp"

#include "GlfwConfigCook.hpp"
#include "Service/Loader/ShaderLoaderService.hpp"

namespace ax::wt
{
    struct WindowCreateParameters
    {
        int32_t width;
        int32_t height;
    };

    class Window
    {
        std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> buffer_{nullptr, nullptr};
        int32_t width_{0};
        int32_t height_{0};
        std::string title_{"Axolotl Engine"};

        std::shared_ptr<Hypodermic::Container> context_{};

    public:
        Window() noexcept
        = default;

        Window(int32_t width, int32_t height, std::string&& title) : width_(width), height_(height),
                                                                     title_(title)
        {
            context_ = ApplicationContext().Build();

            const auto service{context_->resolve<service::GLfwErrorHumanizerService>()};

            if (glfwInit() == GLFW_FALSE)
            {
                const auto error{service->GetError()};

                std::cout << "GLFW initialization failed: " << error << std::endl;
                throw exception::GlfwInitializationException("GLFW initialization failed");
            }

            auto* window{glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr)};

            if (window == nullptr)
            {
                const auto error{service->GetError()};

                std::cout << "Window creation failed with error: " << error << std::endl;
                throw exception::WindowCreationException(error);
            }

            glfwMakeContextCurrent(window);

            gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));

            buffer_ = std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)>(window, &glfwDestroyWindow);
        }

        Window(const WindowCreateParameters& parameters, std::string&& title) : Window(
            parameters.width, parameters.height,
            std::move(title))
        {
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

        void Terminate() const
        {
            glfwTerminate();
        }
    };
} // namespace ax::wt
#endif //_GLFW_WRAPPER_H
