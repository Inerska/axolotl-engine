﻿// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef AXOLOTL_ENGINE_LOGGING_CORE_H
#define AXOLOTL_ENGINE_LOGGING_CORE_H

#include <iostream>
#include <memory>
#include <string>
#include <variant>

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
    struct debug_program_info_t
    {
        struct debug_program_info_time_t
        {
            int32_t hour{};
            int32_t minute{};
            int32_t second{};
            bool is_pm{};

            friend std::ostream &operator<<(std::ostream &os, const debug_program_info_time_t &infoTime)
            {
                os << infoTime.hour << ":" << infoTime.minute << ":" << infoTime.second << " "
                   << (infoTime.is_pm ? "PM" : "AM");

                return os;
            }
        };

        struct debug_program_info_date_t
        {
            int month{};
            int day{};
            int year{};

            debug_program_info_time_t time{};

        private:
            inline std::string get_month_name(int month) const
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

            inline friend std::ostream &operator<<(std::ostream &os, const debug_program_info_date_t &buffer)
            {
                os << buffer.get_month_name(buffer.month) << " " << buffer.day << ", " << buffer.year << " "
                   << buffer.time;

                return os;
            }
        };

    private:
        debug_program_info_date_t date{};

        std::string program_name{};
        std::string method_name{};
    public:

        static debug_program_info_date_t &get_current_date()
        {
            std::time_t time{std::time(0)};
            std::tm *local_time{std::localtime(&time)};
            debug_program_info_time_t time_info{};

            time_info.hour = local_time->tm_hour;
            time_info.minute = local_time->tm_min;
            time_info.second = local_time->tm_sec;
            time_info.is_pm = local_time->tm_hour > 12;

            debug_program_info_date_t date_info{.time = time_info,};

            date_info.month = local_time->tm_mon + 1;
            date_info.day = local_time->tm_mday;
            date_info.year = local_time->tm_year + 1900;

            return date_info;
        }

    };

    struct log_t
    {
        /**
         * @brief Log function for the given logging level and message.
         * @tparam T The type of the content to log.
         * @param level The logging level.
         * @param message The message to log.
         */
        template<typename T>
        constexpr static void log(const log_level_t::type &level, const T &message)
        {
            const auto date{debug_program_info_t::get_current_date()};

            std::cerr << date << "\n" << ax::logging::log_level_t::to_string(level) << ": " << message << "\n";
        }

        /**
         * @brief Log function for the given logging level and message vargs.
         * @tparam T The type of the content to log.
         * @tparam Vargs The types of the vargs.
         * @param level The logging level.
         * @param message The message to log.
         * @param args The vargs.
         */
        template<typename T, typename... Vargs>
        constexpr static void log(const log_level_t::type &level, const T &message, const Vargs &... args)
        {
            const auto date{debug_program_info_t::get_current_date()};

            std::cerr << date << "\n" << ax::logging::log_level_t::to_string(level) << ": " << message << "\n";

            log(level, args...);
        }
    };
};

#endif //AXOLOTL_ENGINE_LOGGING_CORE_H