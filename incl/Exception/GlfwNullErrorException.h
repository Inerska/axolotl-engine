// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_NULL_ERROR_EXCEPTION_H
#define _GLFW_NULL_ERROR_EXCEPTION_H

#include "ExceptionBase.h"

namespace ax::exception
{
    class GlfwNullErrorException final : public ax::exception::ExceptionBase
    {
    public:
        using ExceptionBase::ExceptionBase;
    };
}

#endif //_GLFW_NULL_ERROR_EXCEPTION_H
