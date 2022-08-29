#include "WindowMacOS.h"

@interface ChimeraWindow : NSWindow
{
}
@end

@implementation ChimeraWindow

@end

@interface ChimeraView : NSView
- (BOOL)	acceptsFirstResponder;
- (BOOL)	isOpaque;

@end

@implementation ChimeraView

- (void)_updateContentScale
{
    // TODO
}

- (void)scaleDidChange:(NSNotification *)n
{
    [self _updateContentScale];
}

- (void)viewDidMoveToWindow
{
    // Retina Display support
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(scaleDidChange:)
                                                 name:@"NSWindowDidChangeBackingPropertiesNotification"
                                               object:[self window]];

    // immediately update scale after the view has been added to a window
    [self _updateContentScale];
}

- (void)removeFromSuperview
{
    [super removeFromSuperview];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:@"NSWindowDidChangeBackingPropertiesNotification" object:[self window]];
}

- (BOOL)acceptsFirstResponder
{
	return YES;
}

- (BOOL)isOpaque
{
	return YES;
}

@end

namespace Chimera
{
    WindowMacOS::WindowMacOS(const WindowProps& props, 
        EventQueue& eventQueue)
    {
        Init(props, eventQueue);
    }

    WindowMacOS::~WindowMacOS()
    {
        Shutdown();
    }

    void WindowMacOS::OnUpdate()
    {

    }

    void WindowMacOS::Init(const WindowProps& props, EventQueue& eventQueue)
    {
        NSRect rect = NSMakeRect(props.x, props.y, props.Width, props.Height);
        NSWindowStyleMask styleMask = NSWindowStyleMaskTitled;
        if (props.Closable)
        {
            styleMask |= NSWindowStyleMaskClosable;
        }
        if (props.Resizable)
        {
            styleMask |= NSWindowStyleMaskResizable;
        }
        if (props.Minimizable)
        {
            styleMask |= NSWindowStyleMaskMiniaturizable;
        }
        if (!props.Frame)
        {
            styleMask |= NSWindowStyleMaskFullSizeContentView;
        }
        
        // Setup NSWindow
        ChimeraWindow* w = [[ChimeraWindow alloc]
                initWithContentRect: rect
                styleMask: styleMask
                backing: NSBackingStoreBuffered
                defer: NO];
        
        NSString* title = [NSString stringWithCString:props.Title.c_str()
                                    encoding:[NSString defaultCStringEncoding]];

        if(!props.Title.empty())
        {
            [w setTitle: (NSString*)title];
        }

        if(props.Centered)
        { 
            [w center];
        }
        else
        {
            NSPoint point = NSMakePoint(props.x, props.y);
            point = [w convertPointToScreen:point];
            [w setFrameOrigin: point];
        }
        
        [w setHasShadow:props.HasShadow];
        [w setTitlebarAppearsTransparent:!props.Frame];

        // Setup NSView
        rect = [w backingAlignedRect:rect options:NSAlignAllEdgesOutward];
        ChimeraView* v = [[ChimeraView alloc] initWithFrame:rect];
        [v setHidden:NO];
        [v setNeedsDisplay:YES];
        [v setWantsLayer:YES];

        [w setContentView:v];
        [w makeKeyAndOrderFront:NSApp];
	
        m_Window = ((__bridge_retained void*)w);
        m_View = ((__bridge_retained void*)v);
        eventQueue.Update();
        m_Props = props;
    }
        
    void WindowMacOS::Shutdown()
    {
        // Return ownership to ARC
        __unused id windowObj = (__bridge_transfer id)m_Window;
        __unused id viewObj = (__bridge_transfer id)m_View;
    }

    std::unique_ptr<Window> Window::CreateAppWindow(const WindowProps& props, 
        EventQueue& eventQueue)
    {
        return std::make_unique<WindowMacOS>(props, eventQueue);
    }
}
