#pragma once

extern Chimera::Application* Chimera::CreateApplication();

#if defined(CH_PLATFORM_WINDOWS)
    #include "Windows/EntryPoint.inc"
#elif defined(CH_PLATFORM_MACOS)
    #include "MacOS/EntryPoint.inc"
#endif
