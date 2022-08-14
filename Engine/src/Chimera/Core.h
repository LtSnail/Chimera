#pragma once

#if defined(CH_PLATFORM_WINDOWS)
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(CH_PLATFORM_MACOS)
    #define EXPORT
    #define IMPORT
#else
    #error Unsupported platform!
#endif

#if CH_BUILD_LIB
    #define CH_API EXPORT
#else
    #define CH_API IMPORT
#endif
