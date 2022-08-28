#include "Application.h"

#include "EventQueueMacOS.h"

namespace Chimera
{
    std::unique_ptr<EventQueue> Application::CreateEventQueue()
    {
        return std::make_unique<EventQueueMacOS>();
    }
}
