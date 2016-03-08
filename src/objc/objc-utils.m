/**
 * Copyright (c) 2016, Harrison Bowden, Minneapolis, MN
 * 
 * Permission to use, copy, modify, and/or distribute this software for any purpose
 * with or without fee is hereby granted, provided that the above copyright notice 
 * and this permission notice appear in all copies.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH 
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR
 * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, 
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
 * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 **/

#include "objc-utils.h"
#import "AppDelegate.h"

/* Setup the Objective-c runtime. */
int32_t setup_objc_runtime(int32_t (*app_setup)(void *), int32_t (*app_start)(void), void *arg)
{
    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    NSApplication * application = [NSApplication sharedApplication];

    MyApplicationDelegate * appDelegate = [[[MyApplicationDelegate alloc] init] autorelease];

    [appDelegate setSetup:app_setup argument:arg];
    [appDelegate setStart:app_start];

    [application setDelegate:appDelegate];
    [application run];

    [pool drain];

	return (0);
}

NSString *cstring_to_nsstring(char *string)
{
	NSString *ns = [NSString stringWithUTF8String:string];

	return (ns);
}
