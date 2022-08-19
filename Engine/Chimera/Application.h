#pragma once

#include "Core.h"

namespace Chimera
{
    class CH_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // Should be defined in a client.
    Application* CreateApplication();
}
