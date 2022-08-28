#include "WindowsEventQueue.h"

namespace Chimera
{
    void WindowsEventQueue::Update()
    {

    }

    const Event& WindowsEventQueue::Front()
    {
        return m_Queue.front();
    }

    void WindowsEventQueue::Pop()
    {
        m_Queue.pop();
    }

    bool WindowsEventQueue::Empty()
    {
        return m_Queue.empty();
    }

    std::unique_ptr<EventQueue> EventQueue::CreateEventQueue()
    {
        return std::make_unique<WindowsEventQueue>();
    }
}
