// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_INITIALIZATION_EXCEPTION_H
#define _GLFW_INITIALIZATION_EXCEPTION_H

#include "ExceptionBase.hpp"

namespace ax::exception
{
    class GlfwInitializationException final : public ExceptionBase
    {
    public:
        using ExceptionBase::ExceptionBase;
    };
} // namespace ax::exception
#endif //_GLFW_INITIALIZATION_EXCEPTION_H
