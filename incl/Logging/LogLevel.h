// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef AXOLOTLENGINE_LOGLEVEL_H
#define AXOLOTLENGINE_LOGLEVEL_H

#include <string>

namespace ax::logging
{
    struct LogLevel
    {
        /**
         * @brief The LogLevel enum
         */
        enum struct Level
        {
            Severe, Fatal, Error, Warning, Info, Debug, Verbose, All
        };

        /**
         * Returns the string representation of the given Logging level.
         * @param level
         * @return The string representation of the given Logging level.
         */
        static std::string ToString(const Level &level)
        {
            switch (level)
            {
                case Level::Severe:
                    return "SEVERE";
                case Level::Fatal:
                    return "FATAL";
                case Level::Error:
                    return "ERROR";
                case Level::Warning:
                    return "WARNING";
                case Level::Info:
                    return "INFO";
                case Level::Debug:
                    return "DEBUG";
                case Level::Verbose:
                    return "VERBOSE";
                case Level::All:
                    return "ALL";
                default:
                    return "UNKNOWN";
            }
        }
    };
};

#endif //AXOLOTLENGINE_LOGLEVEL_H
