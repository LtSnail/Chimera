#include "EventQueueMacOS.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

void Chimera::PushEvent(EventQueueMacOS* eq, std::shared_ptr<const Event> ev)
{
    eq->m_Queue.push(ev);
}

@interface WindowEventsObserver : NSObject
{
}
@end

@implementation WindowEventsObserver
{
    Chimera::EventQueueMacOS* _eq;
}

- (void)_windowWillClose: (NSNotification*) notification
{
    Chimera::PushEvent(_eq, std::make_shared<const Chimera::WindowCloseEvent>());
}

- (void)_windowDidResize: (NSNotification*) notification
{
    NSWindow* window = (NSWindow*)[notification object];
    NSRect rect = [window contentRectForFrameRect:[window frame]];
    Chimera::PushEvent(_eq, std::make_shared<const Chimera::WindowResizeEvent>(rect.size.width, rect.size.height));
}

- (instancetype)initWithEventQueue: (Chimera::EventQueueMacOS*) eq
{
    [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(_windowWillClose:)
        name: NSWindowWillCloseNotification object: nil];
    [[NSNotificationCenter defaultCenter] addObserver: self selector:@selector(_windowDidResize:)
        name:NSWindowDidResizeNotification object:nil];

    self = [super init];
    if (self) {
        _eq = eq;
    }
    return self;
}

@end


namespace Chimera
{
    EventQueueMacOS::EventQueueMacOS()
    {
        WindowEventsObserver* observerObj = [[WindowEventsObserver alloc] initWithEventQueue:this];
        m_WindowEventsObserver = ((__bridge_retained void*)observerObj);
    }

    EventQueueMacOS::~EventQueueMacOS()
    {
        // Return ownership to ARC
        __unused id observerObj = (__bridge_transfer id)m_WindowEventsObserver;
    }

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
    }

    std::shared_ptr<const Event> EventQueueMacOS::Front()
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

    std::unique_ptr<EventQueue> EventQueue::CreateEventQueue()
    {
        return std::make_unique<EventQueueMacOS>();
    }
}
