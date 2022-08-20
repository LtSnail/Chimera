#pragma once

extern Chimera::Application* Chimera::CreateApplication();

#if defined(CH_PLATFORM_WINDOWS)
    #include "Windows/main.inc"
#elif defined(CH_PLATFORM_MACOS)
    #include "MacOS/main.inc"
#endif
