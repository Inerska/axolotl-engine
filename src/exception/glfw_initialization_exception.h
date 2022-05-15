// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _GLFW_INITIALIZATION_EXCEPTION_H
#define _GLFW_INITIALIZATION_EXCEPTION_H

#include "exception_base.h"

namespace ax::exception
{
    class glfw_initialization_exception : public ax::exception::exception_base
    {
    public:
        glfw_initialization_exception(const std::string &message) : exception_base(message)
        {}
    };
}
#endif //_GLFW_INITIALIZATION_EXCEPTION_H