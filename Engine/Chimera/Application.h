#pragma once

#include "chpch.h"

#include "Core.h"
#include "EventQueue.h"
#include "Window.h"

namespace Chimera
{
    class CHIMERA_API Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        std::unique_ptr<EventQueue> m_EventQueue;
    };

    // Should be defined in a client.
    Application* CreateApplication();
}
