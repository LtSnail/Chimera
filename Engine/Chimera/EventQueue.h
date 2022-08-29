#pragma once

#include "Core.h"

#include "Events/Event.h"

namespace Chimera
{
    class CHIMERA_API EventQueue
    {
    public:
        virtual void Update() = 0;
        virtual std::shared_ptr<const Event> Front() = 0;
        virtual void Pop() = 0;
        virtual bool Empty() = 0;

        virtual ~EventQueue() = default;

        static std::unique_ptr<EventQueue> CreateEventQueue();
    };
}
