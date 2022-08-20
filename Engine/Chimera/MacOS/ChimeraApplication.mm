#import "ChimeraApplication.h"

#import "AppDelegate.h"

#include "../Application.h"
#include "../Core.h"
#include "../Log.h"

int ChimeraApplicationMain(int argc, const char **argv, Chimera::Application* app)
{
    (void)(argc);
    (void)(argv);
    
    Chimera::Log::Init();

    CH_CORE_WARN("Core Log!");
    CH_INFO("Client Log!");
	
	NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
	Class principalClass =
		NSClassFromString([infoDictionary objectForKey:@"NSPrincipalClass"]);
    ChimeraApplication *applicationObject = [principalClass sharedApplication];

    [NSApp setDelegate: [AppDelegate new]];
    
    NSStoryboard* sb = [NSStoryboard storyboardWithName:@"Main"
                                                  bundle:nil];
    NSWindowController* vc = [sb instantiateInitialController];
    [vc showWindow:nil];

    if ([applicationObject respondsToSelector:@selector(run)])
    {
        [applicationObject
            performSelectorOnMainThread:@selector(run)
            withObject:nil
            waitUntilDone:YES];
    }
    
    delete app;
	
	return 0;
}

@implementation ChimeraApplication;

- (void)_windowWillClose: (NSNotification*) notification
{
    AppDelegate* delegate = [NSApp delegate];
    
    if ([delegate respondsToSelector: @selector(applicationShouldTerminateAfterLastWindowClosed:)])
    {
        if ([delegate applicationShouldTerminateAfterLastWindowClosed: self])
        {
            [[NSNotificationCenter defaultCenter]
                postNotificationName:NSApplicationWillTerminateNotification
                object:NSApp];
            
            [self terminate: self];
        }
    }
}

- (void)run
{
    NSNotificationCenter* nc = [NSNotificationCenter defaultCenter];
    
    [nc addObserver: self selector: @selector(_windowWillClose:)
        name: NSWindowWillCloseNotification object: nil];
    
	[self finishLaunching];
    
	[[NSNotificationCenter defaultCenter]
		postNotificationName:NSApplicationWillFinishLaunchingNotification
		object:NSApp];
	/*[[NSNotificationCenter defaultCenter]
		postNotificationName:NSApplicationDidFinishLaunchingNotification
		object:NSApp];*/
	
	shouldKeepRunning = YES;
	do
	{
		NSEvent *event =
			[self
				nextEventMatchingMask:NSEventMaskAny
				untilDate:[NSDate distantFuture]
				inMode:NSDefaultRunLoopMode
				dequeue:YES];
		
		[self sendEvent:event];
		[self updateWindows];
	} while (shouldKeepRunning);
}

- (void)terminate:(id)sender
{
	shouldKeepRunning = NO;
}

@end
