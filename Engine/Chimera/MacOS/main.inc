/* This file is a MacOS-specific part of Entrypoint.h
 * and compiled in a client application
 */

 #import <Cocoa/Cocoa.h>

@interface ChimeraApplication : NSApplication

@property Chimera::Application* application;

- (void)run;

@end

@implementation ChimeraApplication;


- (void)run
{    
	[[NSNotificationCenter defaultCenter]
		postNotificationName:NSApplicationWillFinishLaunchingNotification
		object:NSApp];
	[[NSNotificationCenter defaultCenter]
		postNotificationName:NSApplicationDidFinishLaunchingNotification
		object:NSApp];
	
    _application->Run();
}

@end

int main(int argc, const char * argv[]) 
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	ChimeraApplication* applicationObject = [ChimeraApplication alloc];

    Chimera::Application* app = Chimera::CreateApplication();
    applicationObject.application = app;

    if ([applicationObject respondsToSelector:@selector(run)])
	{
		[applicationObject
			performSelectorOnMainThread:@selector(run)
			withObject:nil
			waitUntilDone:YES];
	}
	
	[pool release];

    delete app;
	
	return 0;
}
