#pragma once

#include "Core.h"

#include "Events/Event.h"

namespace Chimera
{
    class CHIMERA_API EventQueue
    {
    public:
        virtual void Update() = 0;
        virtual const Event& Front() = 0;
        virtual void Pop() = 0;
        virtual bool Empty() = 0;

        virtual ~EventQueue() = default;
    };
}
