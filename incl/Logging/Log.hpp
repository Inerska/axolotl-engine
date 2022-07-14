// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef AXOLOTL_ENGINE_LOGGING_CORE_H
#define AXOLOTL_ENGINE_LOGGING_CORE_H

#include "LogLevel.hpp"
#include <iostream>
#include <string>

namespace ax::logging
{
    /**
     * @brief The Logger struct
     */
    struct DebugProgramInfo
    {
        struct DebugProgramInfoTime
        {
            int32_t hour{};
            int32_t minute{};
            int32_t second{};
            bool is_pm{};

            friend std::ostream& operator<<(std::ostream& os, const DebugProgramInfoTime& infoTime)
            {
                os << infoTime.hour << ":" << infoTime.minute << ":" << infoTime.second << " "
                    << (infoTime.is_pm ? "PM" : "AM");

                return os;
            }
        };

        struct DebugProgramInfoDate
        {
            int month{};
            int day{};
            int year{};

            DebugProgramInfoTime time{};

        private:
            [[nodiscard]] static std::string GetMonthName(const int month)
            {
                switch (month)
                {
                case 1:
                    return "January";
                case 2:
                    return "February";
                case 3:
                    return "March";
                case 4:
                    return "April";
                case 5:
                    return "May";
                case 6:
                    return "June";
                case 7:
                    return "July";
                case 8:
                    return "August";
                case 9:
                    return "September";
                case 10:
                    return "October";
                case 11:
                    return "November";
                case 12:
                    return "December";
                default:
                    return "Unknown";
                }
            }


        public:
            friend std::ostream& operator<<(std::ostream& os, const DebugProgramInfoDate& buffer)
            {
                os << GetMonthName(buffer.month) << " " << buffer.day << ", " << buffer.year << " "
                    << buffer.time;

                return os;
            }
        };

    private:
        DebugProgramInfoDate date_{};

        std::string program_name_{};
        std::string method_name_{};
    public:
        static DebugProgramInfoDate GetCurrentDate()
        {
            const std::time_t time{std::time(nullptr)};
            const std::tm *local_time{std::localtime(&time)};
            DebugProgramInfoTime time_info;

            time_info.hour = local_time->tm_hour;
            time_info.minute = local_time->tm_min;
            time_info.second = local_time->tm_sec;
            time_info.is_pm = local_time->tm_hour > 12;

            DebugProgramInfoDate date_info{.time = time_info,};

            date_info.month = local_time->tm_mon + 1;
            date_info.day = local_time->tm_mday;
            date_info.year = local_time->tm_year + 1900;

            return date_info;
        }
    };

    struct Logging
    {
        /**
         * @brief Log function for the given Logging level and message.
         * @tparam T The Level of the content to Log.
         * @param level The Logging level.
         * @param message The message to Log.
         */
        template <typename T>
        constexpr static void Log(const Level& level, const T& message)
        {
            const auto date{DebugProgramInfo::GetCurrentDate()};

            std::cerr << date << "\n" << ToString(level) << ": " << message << "\n";
        }

        /**
         * @brief Log function for the given Logging level and message vargs.
         * @tparam T The Level of the content to Log.
         * @tparam VArgs The types of the vargs.
         * @param level The Logging level.
         * @param message The message to Log.
         * @param args The vargs.
         */
        template <typename T, typename... VArgs>
        constexpr static void Log(const Level& level, const T& message, const VArgs&... args)
        {
            const auto date{DebugProgramInfo::GetCurrentDate()};

            std::cerr << date << "\n" << ToString(level) << ": " << message << "\n";

            (Log(level, args), ...);
        }
    };
} // namespace ax::logging

#endif //AXOLOTL_ENGINE_LOGGING_CORE_H
