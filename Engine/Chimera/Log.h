#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"

namespace Chimera
{
    class CH_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core Log macros.
#define CH_CORE_TRACE(...)   ::Chimera::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CH_CORE_INFO(...)    ::Chimera::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CH_CORE_WARN(...)    ::Chimera::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CH_CORE_ERROR(...)   ::Chimera::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CH_CORE_FATAL(...)   ::Chimera::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros.
#define CH_TRACE(...)        ::Chimera::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CH_INFO(...)         ::Chimera::Log::GetClientLogger()->info(__VA_ARGS__)
#define CH_WARN(...)         ::Chimera::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CH_ERROR(...)        ::Chimera::Log::GetClientLogger()->error(__VA_ARGS__)
#define CH_FATAL(...)        ::Chimera::Log::GetClientLogger()->fatal(__VA_ARGS__)
