// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#include <catch2/catch.hpp>
#include <string>
#include "Logging/Log.h"

using logging_core = ax::logging::Logging;
using logging_level = ax::logging::LogLevel;

TEST_CASE("Logging level string is the same as expected", "[Logging]")
{
    REQUIRE(std::string(logging_level::ToString(logging_level::Level::Verbose)).compare("VERBOSE") == 0);
}

TEST_CASE("Logging debug get day should be valid for int", "[Logging]")
{
    const auto date{ax::logging::DebugProgramInfo::GetCurrentDate()};

    REQUIRE(date.day_ > 0);
    REQUIRE(date.day_ <= 31);
}

TEST_CASE("Logging debug get date year should be valid for int", "[Logging]")
{
    const auto date{ax::logging::DebugProgramInfo::GetCurrentDate()};
    const auto year{date.year_};

    REQUIRE(typeid(year) == typeid(int));
    REQUIRE(year > 0);
}

TEST_CASE("Log should not throw any exception", "[Logging]")
{
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Verbose, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Info, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Warning, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Error, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Severe, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Fatal, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::All, "Logging test"));
    REQUIRE_NOTHROW(logging_core::Log(logging_level::Level::Debug, "Logging test"));
}