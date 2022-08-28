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
                //Event curEvent;
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
                //if(curEvent.type != EventType::None)
                {
                    //m_Queue.push(curEvent);
                }
                
                [NSApp sendEvent:nsEvent];
            }
            while (nsEvent);
            
        }
        [NSApp updateWindows];
    }

    //Event& EventQueueMacOS::Front()
    //{

    //}

    void EventQueueMacOS::Pop()
    {

    }

    bool EventQueueMacOS::Empty()
    {
        return false;
    }
}
