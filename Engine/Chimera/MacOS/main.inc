/* This file is a MacOS-specific part of Entrypoint.h
 * and compiled in a client application
 */

#import "ChimeraApplication.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Setup code that might create autoreleased objects goes here.
    }

    // Create app

    return ChimeraApplicationMain(argc, argv);
}
