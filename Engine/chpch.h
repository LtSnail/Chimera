#pragma once

#include <iostream>
#include <memory>
#include <functional>

#include <string>
#include <sstream>
#include <vector>

#ifdef CHIMERA_PLATFORM_WINDOWS
    #include <sdkddkver.h>
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
#endif

#ifdef CHIMERA_PLATFORM_MACOS
    #ifdef __OBJC__
        #import <Cocoa/Cocoa.h>
        #import <simd/simd.h>
        #import <Metal/Metal.h>
        #import <MetalKit/MetalKit.h>
        #import <ModelIO/ModelIO.h>
    #endif
#endif

