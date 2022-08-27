#pragma once

#if defined(CHIMERA_PLATFORM_WINDOWS)
    #define EXPORT __declspec(dllexport)
    #define IMPORT __declspec(dllimport)
#elif defined(CHIMERA_PLATFORM_MACOS)
    #define EXPORT __attribute__ ((visibility ("default")))
    #define IMPORT __attribute__ ((visibility ("default")))
#else
    #error Unsupported platform!
#endif

#if defined(CHIMERA_BUILD_LIB)
    #define CHIMERA_API EXPORT
#else
    #define CHIMERA_API IMPORT
#endif

#define BIT(x) (1 << x)

#define UNUSED(x) (void)(x)
