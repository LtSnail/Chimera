#include "chpch.h"

#include "EventQueue.h"

namespace Chimera
{
    class CHIMERA_API EventQueueMacOS : public EventQueue
    {
    public:
        EventQueueMacOS();
        ~EventQueueMacOS();

        virtual void Update() override;
        virtual std::shared_ptr<const Event> Front() override;
        virtual void Pop() override;
        virtual bool Empty() override;

    private:
        friend void PushEvent(EventQueueMacOS* eq, std::shared_ptr<const Event> ev);
        std::queue<std::shared_ptr<const Event>> m_Queue;

        // WindowCloseObserver*
        void* m_WindowCloseObserver;
    };
}
