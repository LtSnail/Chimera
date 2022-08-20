#import <Cocoa/Cocoa.h>

#include "Application.h"

int ChimeraApplicationMain(int argc, const char **argv, Chimera::Application* app);

@interface ChimeraApplication : NSApplication
{
	bool shouldKeepRunning;
}

- (void)run;
- (void)terminate:(id)sender;

@end
