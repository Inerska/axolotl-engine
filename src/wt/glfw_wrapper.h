// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_WRAPPER_H
#define _GLFW_WRAPPER_H

#include <memory>
#include <string>
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

        window_t() noexcept: buffer_(nullptr, nullptr)
        {}

        window_t(int32_t width, int32_t height, std::string title);

        ~window_t() noexcept
        {
            if (buffer_)
            {
                glfwDestroyWindow(buffer_.get());
            }

            glfwTerminate();
        }

        [[nodiscard]] inline bool should_close() const
        {
            return glfwWindowShouldClose(buffer_.get());
        }

        void swap_buffers()
        {
            glfwSwapBuffers(buffer_.get());
        }
    };
}
#endif //_GLFW_WRAPPER_H