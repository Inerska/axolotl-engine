﻿// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
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

TEST_CASE("Logging debug get day should be valid for int", "[logging]")
{
    const auto date{ax::logging::debug_program_info_t::get_current_date()};

    REQUIRE(date.day > 0);
    REQUIRE(date.day <= 31);
}

TEST_CASE("Logging debug get date month should be valid for int", "[logging]")
{
    const auto date{ax::logging::debug_program_info_t::get_current_date()};
    const auto month{date.month};

    if (std::holds_alternative<int>(month))
    {
        const auto month_int{std::get<int>(month)};

        REQUIRE(month_int >= 1);
        REQUIRE(month_int <= 12);
    }
}

TEST_CASE("Logging debug get date year should be valid for int", "[logging]")
{
    const auto date{ax::logging::debug_program_info_t::get_current_date()};
    const auto year{date.year};

    REQUIRE(typeid(year) == typeid(int));
    REQUIRE(year > 0);
}