#include "Application.h"


namespace Chimera
{
    Application::Application()
    {
        m_EventQueue = EventQueue::CreateEventQueue();
        m_Window = Window::CreateAppWindow(WindowProps(), *m_EventQueue);
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        bool isRunning = true;

        while (isRunning)
        {
            m_EventQueue->Update();
            m_Window->Update();
            
            while (!m_EventQueue->Empty())
            {
                auto ev = m_EventQueue->Front();
                if ((*ev).GetEventType() == EventType::EventTypeWindowClose)
                {
                    isRunning = false;
                }

                m_EventQueue->Pop();
            }
        }
    }
}
