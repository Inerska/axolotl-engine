// Copyright (c) Alexis Chân Gridel. All Rights Reserved.
// Copyright (c) Axolotl Engine contributors. All Rights Reserved.
// Licensed under the GNU General Public License v3.0.
// See the LICENSE file in the project root for more information.

#ifndef AXOLOTL_ENGINE_LOGGING_CORE_H
#define AXOLOTL_ENGINE_LOGGING_CORE_H

#include <string>
#include <sstream>
#include <iostream>

namespace ax::logging
{
    /**
     * @brief The LogLevel struct
     */
    struct LogLevel
    {
        /**
         * @brief The LogLevel enum
         */
        enum struct Level
        {
            Severe,
            Fatal,
            Error,
            Warning,
            Info,
            Debug,
            Verbose,
            All
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

    /**
     * @brief The Logger struct
     */
    struct DebugProgramInfo
    {
        struct DebugProgramInfoTime
        {
            int32_t hour_{};
            int32_t minute_{};
            int32_t second_{};
            bool isPm_{};

            friend std::ostream &operator<<(std::ostream &os, const DebugProgramInfoTime &infoTime)
            {
                os << infoTime.hour_ << ":" << infoTime.minute_ << ":" << infoTime.second_ << " "
                   << (infoTime.isPm_ ? "PM" : "AM");

                return os;
            }
        } __attribute__((aligned(16)));

        struct DebugProgramInfoDate
        {
            int month_{};
            int day_{};
            int year_{};

            DebugProgramInfoTime time_{};

        private:
            [[nodiscard]] static inline std::string GetMonthName(int month)
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
            inline friend std::ostream &operator<<(std::ostream &os, const DebugProgramInfoDate &buffer)
            {
                os << buffer.GetMonthName(buffer.month_) << " " << buffer.day_ << ", " << buffer.year_ << " "
                   << buffer.time_;

                return os;
            }
        };

    private:
        DebugProgramInfoDate date_{};

        std::string programName_{};
        std::string methodName_{};
    public:

        static DebugProgramInfoDate GetCurrentDate()
        {
            std::time_t time{std::time(nullptr)};
            std::tm *local_time{std::localtime(&time)};
            DebugProgramInfoTime time_info{};

            time_info.hour_ = local_time->tm_hour;
            time_info.minute_ = local_time->tm_min;
            time_info.second_ = local_time->tm_sec;
            time_info.isPm_ = local_time->tm_hour > 12;

            DebugProgramInfoDate date_info{.time_ = time_info,};

            date_info.month_ = local_time->tm_mon + 1;
            date_info.day_ = local_time->tm_mday;
            date_info.year_ = local_time->tm_year + 1900;

            return date_info;
        }

    } __attribute__((aligned(128)));

    struct Logging
    {
        /**
         * @brief Log function for the given Logging level and message.
         * @tparam T The Level of the content to Log.
         * @param level The Logging level.
         * @param message The message to Log.
         */
        template<typename T>
        constexpr static void Log(const LogLevel::Level &level, const T &message)
        {
            const auto date{DebugProgramInfo::GetCurrentDate()};

            std::cerr << date << "\n" << ax::logging::LogLevel::ToString(level) << ": " << message << "\n";
        }

        /**
         * @brief Log function for the given Logging level and message vargs.
         * @tparam T The Level of the content to Log.
         * @tparam Vargs The types of the vargs.
         * @param level The Logging level.
         * @param message The message to Log.
         * @param args The vargs.
         */
        template<typename T, typename... Vargs>
        constexpr static void Log(const LogLevel::Level &level, const T &message, const Vargs &... args)
        {
            const auto date{DebugProgramInfo::GetCurrentDate()};

            std::cerr << date << "\n" << ax::logging::LogLevel::ToString(level) << ": " << message << "\n";

            (Log(level, args), ...);
        }
    };
}

#endif //AXOLOTL_ENGINE_LOGGING_CORE_H