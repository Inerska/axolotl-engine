// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#include <catch2/catch.hpp>
#include <string>
#include "logging/logging_core.h"

using logging_core = ax::logging::log_t;
using logging_level = ax::logging::log_level_t;

TEST_CASE("Logging level string is the same as expected", "[logging]")
{
    REQUIRE(std::string(logging_level::to_string(logging_level::verbose)).compare("VERBOSE") == 0);
}