#include "EventQueue.h"

namespace Chimera
{
    class CHIMERA_API EventQueueMacOS : public EventQueue
    {
    public:
        virtual void Update() override;
        //virtual Event& Front() override;
        virtual void Pop() override;
        virtual bool Empty() override;

    private:
        //std::queue m_Queue;
    };
}
