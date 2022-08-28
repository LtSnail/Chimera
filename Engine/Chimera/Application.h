#pragma once

#include "chpch.h"

#include "Core.h"
#include "EventQueue.h"


namespace Chimera
{
    class CHIMERA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<EventQueue> CreateEventQueue();
    };

    // Should be defined in a client.
    Application* CreateApplication();
}
