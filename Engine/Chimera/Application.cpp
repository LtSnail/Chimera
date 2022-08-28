#include "Application.h"

namespace Chimera
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        std::unique_ptr<EventQueue> eventQueue = EventQueue::CreateEventQueue();

        bool isRunning = true;

        while (isRunning)
        {
            while (!eventQueue->Empty())
            {
            }

            eventQueue->Pop();
        }
    }
}