#include "chpch.h"

#include "EventQueue.h"

namespace Chimera
{
    class WindowsEventQueue : public EventQueue
    {
    public:
        virtual void Update() override;
        virtual const Event& Front() override;
        virtual void Pop() override;
        virtual bool Empty() override;

    private:
        std::queue<Event> m_Queue;
    };
}
