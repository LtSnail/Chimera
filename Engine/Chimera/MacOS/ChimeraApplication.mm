#import "ChimeraApplication.h"

#include "../Application.h"
#include "../Core.h"
#include "../EntryPoint.h"
#include "../Log.h"

int ChimeraApplicationMain(int argc, const char **argv)
{
    (void)(argc);
    (void)(argv);
    
    Chimera::Log::Init();

    CH_CORE_WARN("Core Log!");
    CH_INFO("Client Log!");

    //Chimera::Application* app = Chimera::CreateApplication();
    // app->Run();
    //delete app;
	
	NSDictionary *infoDictionary = [[NSBundle mainBundle] infoDictionary];
	Class principalClass =
		NSClassFromString([infoDictionary objectForKey:@"NSPrincipalClass"]);
	NSApplication *applicationObject = [principalClass sharedApplication];
    
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
	
	return 0;
}

@implementation ChimeraApplication

- (void)run
{
//	[self finishLaunching];
	[[NSNotificationCenter defaultCenter]
		postNotificationName:NSApplicationWillFinishLaunchingNotification
		object:NSApp];
	[[NSNotificationCenter defaultCenter]
		postNotificationName:NSApplicationDidFinishLaunchingNotification
		object:NSApp];
	
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
