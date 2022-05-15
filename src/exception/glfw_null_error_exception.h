// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_NULL_ERROR_EXCEPTION_H
#define _GLFW_NULL_ERROR_EXCEPTION_H

#include "exception_base.h"

namespace ax::exception
{
    class glfw_null_error_exception final : public ax::exception::exception_base
    {
    public:
        explicit glfw_null_error_exception(const char *message) : exception_base(message)
        {}
    };
}

#endif //_GLFW_NULL_ERROR_EXCEPTION_H
