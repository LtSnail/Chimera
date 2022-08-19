#import <Cocoa/Cocoa.h>

int ChimeraApplicationMain(int argc, const char **argv);

@interface ChimeraApplication : NSApplication
{
	bool shouldKeepRunning;
}

- (void)run;
- (void)terminate:(id)sender;

@end
