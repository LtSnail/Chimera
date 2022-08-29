#include "Application.h"

#include "EventQueue.h"
#include "Window.h"

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
        auto eventQueue = EventQueue::CreateEventQueue();
        auto window = Window::CreateAppWindow(WindowProps(), *eventQueue);

        bool isRunning = true;

        while (isRunning)
        {
            eventQueue->Update();
            
            while (!eventQueue->Empty())
            {
                auto ev = eventQueue->Front();
                if ((*ev).GetEventType() == EventType::EventTypeWindowClose)
                {
                    isRunning = false;
                }

                eventQueue->Pop();
            }
        }
    }
}
