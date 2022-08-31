/* This file is a MacOS-specific part of Entrypoint.h
 * and compiled in a client application
 */

#include "chpch.h"

#include "Log.h"

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
	@autoreleasepool 
	{
        Chimera::Log::Init();
         
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

		delete app;
	}
	
	return 0;
}
