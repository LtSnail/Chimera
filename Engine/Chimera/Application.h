#pragma once

#include "chpch.h"

#include "Core.h"


namespace Chimera
{
    class CHIMERA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // Should be defined in a client.
    Application* CreateApplication();
}
