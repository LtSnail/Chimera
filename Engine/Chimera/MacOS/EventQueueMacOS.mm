#include "EventQueueMacOS.h"

namespace Chimera
{
    void EventQueueMacOS::Update()
    {
        @autoreleasepool
        {
            NSEvent* nsEvent = nil;
            
            do
            {
                nsEvent = [NSApp nextEventMatchingMask:NSEventMaskAny untilDate:nil inMode:NSDefaultRunLoopMode dequeue:YES];

                switch(nsEvent.type)
                {
                    case NSEventTypeSystemDefined:
                        break;
                    case NSEventTypeKeyDown:
                        break;
                    case NSEventTypeKeyUp:
                        break;
                    case NSEventTypeLeftMouseDown:
                        break;
                    case NSEventTypeLeftMouseUp:
                        break;
                    case NSEventTypeRightMouseDown:
                        break;
                    case NSEventTypeRightMouseUp:
                        break;
                    case NSEventTypeMouseMoved:
                        break;
                    case NSEventTypeScrollWheel:
                        break;
                    default:
                        break;
                }
                
                [NSApp sendEvent:nsEvent];
            }
            while (nsEvent);
            
        }
        [NSApp updateWindows];
    }

    const Event& EventQueueMacOS::Front()
    {
        return m_Queue.front();
    }

    void EventQueueMacOS::Pop()
    {
        m_Queue.pop();
    }

    bool EventQueueMacOS::Empty()
    {
        return m_Queue.empty();
    }
}
