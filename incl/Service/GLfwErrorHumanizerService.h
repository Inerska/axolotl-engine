// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_ERROR_HUMANIZER_SERVICE_H
#define _GLFW_ERROR_HUMANIZER_SERVICE_H

#include <string>
#include <GLFW/glfw3.h>
#include "../Exception/GlfwNullErrorException.h"

namespace ax::service
{
    class GLfwErrorHumanizerService
    {
    public:
        static inline std::string GetError() noexcept
        {
            const char *error = nullptr;
            (void)glfwGetError(&error);

            return std::string{error == nullptr ? error : "No error"};
        }
    };
} // namespace ax::service

#endif //_GLFW_ERROR_HUMANIZER_SERVICE_H
