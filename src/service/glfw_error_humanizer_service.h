// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_ERROR_HUMANIZER_SERVICE_H
#define _GLFW_ERROR_HUMANIZER_SERVICE_H

#include <string>
#include <GLFW/glfw3.h>
#include "../exception/glfw_null_error_exception.h"

namespace ax::service
{
    class glfw_error_humanizer_service
    {
    public:
        static inline std::string get_human_readable_error() noexcept
        {
            const char *error = nullptr;
            (void)glfwGetError(&error);

            return std::string{error == nullptr ? error : "No error"};
        }
    };
}

#endif //_GLFW_ERROR_HUMANIZER_SERVICE_H
