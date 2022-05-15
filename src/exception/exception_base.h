// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _EXCEPTION_BASE_H
#define _EXCEPTION_BASE_H

#include <stdexcept>

namespace ax::exception
{
    class exception_base : public std::runtime_error
    {
    public:
        explicit exception_base(const std::string &message) : std::runtime_error(message)
        {}

        ~exception_base() override = default;
    };
}
#endif //_EXCEPTION_BASE_H