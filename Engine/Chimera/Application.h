#pragma once

#include "Core.h"
#include "EventQueue.h"

#include <memory>

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
