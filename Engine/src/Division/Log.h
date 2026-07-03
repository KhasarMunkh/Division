#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Division {
    class DIVISION_API Log {
    private:
        inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
        inline static std::shared_ptr<spdlog::logger> s_ClientLogger;

    public:
        static void Init();
        inline static const std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static const std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    };

}  // namespace Division

// Core log macros
#define DV_CORE_TRACE(...) ::Division::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define DV_CORE_INFO(...)  ::Division::Log::GetCoreLogger()->info(__VA_ARGS__)
#define DV_CORE_WARN(...)  ::Division::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define DV_CORE_ERROR(...) ::Division::Log::GetCoreLogger()->error(__VA_ARGS__)
#define DV_CORE_FATAL(...) ::Division::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define DV_TRACE(...) ::Division::Log::GetClientLogger()->trace(__VA_ARGS__)
#define DV_INFO(...)  ::Division::Log::GetClientLogger()->info(__VA_ARGS__)
#define DV_WARN(...)  ::Division::Log::GetClientLogger()->warn(__VA_ARGS__)
#define DV_ERROR(...) ::Division::Log::GetClientLogger()->error(__VA_ARGS__)
#define DV_FATAL(...) ::Division::Log::GetClientLogger()->fatal(__VA_ARGS__)
