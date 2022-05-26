// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef AXOLOTL_ENGINE_LOGGING_CORE_H
#define AXOLOTL_ENGINE_LOGGING_CORE_H

#include <iostream>
#include <memory>

namespace ax::logging
{
    /**
     * @brief The LogLevel struct
     */
    struct log_level_t
    {
        /**
         * @brief The LogLevel enum
         */
        enum type
        {
            severe, fatal, error, warning, info, debug, verbose, all
        };

        /**
         * Returns the string representation of the given logging level.
         * @param level
         * @return The string representation of the given logging level.
         */
        static constexpr auto to_string(const type &level)
        {
            switch (level)
            {
                case severe:
                    return "SEVERE";
                case fatal:
                    return "FATAL";
                case error:
                    return "ERROR";
                case warning:
                    return "WARNING";
                case info:
                    return "INFO";
                case debug:
                    return "DEBUG";
                case verbose:
                    return "VERBOSE";
                case all:
                    return "ALL";
                default:
                    return "UNKNOWN";
            }
        }
    };

    /**
     * @brief The Logger struct
     */
    struct log_t
    {
        template<typename T>
        constexpr static void log(const log_level_t::type &level, const T &message)
        {
            std::cout << "[" << log_level_t::to_string(level) << "] " << message << std::endl;
        }

        template<typename T, typename... Vargs>
        constexpr static void log(const log_level_t::type &level, const T &message, const Vargs &... args)
        {
            std::cout << "[" << log_level_t::to_string(level) << "] " << message << " ";
            log(level, args...);
        }
    };
};

#endif //AXOLOTL_ENGINE_LOGGING_CORE_H