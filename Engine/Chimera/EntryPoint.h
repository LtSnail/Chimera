#pragma once

extern Chimera::Application* Chimera::CreateApplication();

#if defined(CHIMERA_PLATFORM_WINDOWS)
    #include "Windows/main.inc"
#elif defined(CHIMERA_PLATFORM_MACOS)
    #include "MacOS/main.inc"
#endif
