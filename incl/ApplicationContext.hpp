// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef _APPLICATION_CONTEXT_H
#define _APPLICATION_CONTEXT_H

#include <Hypodermic/Hypodermic.h>

#include "Logging/Log.hpp"
#include "Service/GLfwErrorHumanizerService.hpp"

class ApplicationContext
{
public:
    ApplicationContext()
    {
        using Hypodermic::ContainerBuilder;

        ContainerBuilder builder{};
        builder.registerType<ax::logging::Logging>();
        builder.registerType<ax::service::GLfwErrorHumanizerService>();

        container_ = builder.build();
    }

    auto Build() -> std::shared_ptr<Hypodermic::Container>
    {
        return container_;
    }
    
private:
    std::shared_ptr<Hypodermic::Container> container_;
};

#endif // _APPLICATION_CONTEXT_H
