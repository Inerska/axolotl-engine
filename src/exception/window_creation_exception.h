// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _WINDOW_CREATION_EXCEPTION_H
#define _WINDOW_CREATION_EXCEPTION_H

#include "exception_base.h"

namespace ax::exception
{
    class window_creation_exception final : public ax::exception::exception_base
    {
    public:
        window_creation_exception(const std::string &message) : exception_base(message)
        {}
    };
}

#endif //_WINDOW_CREATION_EXCEPTION_H