/*
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#import <Cocoa/Cocoa.h>
#include <LDL/BaseWin.h>
#include <LDL/macOS/MainWin.h>

// LDL_WindowDelegate receives window-level notifications from Cocoa
@interface LDL_WindowDelegate : NSObject <NSWindowDelegate>
{
@public
    LDL_MainWindow* mainWindow;
}
@end

@implementation LDL_WindowDelegate

- (BOOL)windowShouldClose:(id)sender
{
    LDL_EventHandlerStop(&mainWindow->EventHandler);
    return NO;
}

- (void)windowDidResize:(NSNotification*)notification
{
    NSWindow* window = (NSWindow*)mainWindow->Window;
    NSRect    frame  = [window contentRectForFrameRect:[window frame]];

    LDL_Event report;
    report.Type            = LDL_EventIsResize;
    report.u.Resize.Width  = (size_t)frame.size.width;
    report.u.Resize.Height = (size_t)frame.size.height;
    LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
}

@end

// LDL_ContentView captures keyboard and mouse events inside the window
@interface LDL_ContentView : NSView
{
@public
    LDL_MainWindow* mainWindow;
}
@end

@implementation LDL_ContentView

- (BOOL)acceptsFirstResponder { return YES; }
- (BOOL)canBecomeKeyView      { return YES; }

- (void)mouseMoved:(NSEvent*)event
{
    NSPoint pos = [self convertPoint:[event locationInWindow] fromView:nil];

    LDL_Event report;
    report.Type          = LDL_EventIsMouseMove;
    report.u.Mouse.PosX  = (size_t)pos.x;
    report.u.Mouse.PosY  = (size_t)([self bounds].size.height - pos.y);
    LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
}

- (void)mouseDragged:(NSEvent*)event     { [self mouseMoved:event]; }
- (void)rightMouseDragged:(NSEvent*)event { [self mouseMoved:event]; }
- (void)otherMouseDragged:(NSEvent*)event { [self mouseMoved:event]; }

- (void)LDL_handleMouseButton:(NSEvent*)event state:(size_t)state
{
    NSPoint pos    = [self convertPoint:[event locationInWindow] fromView:nil];
    size_t  button = 0;

    switch ([event buttonNumber])
    {
        case 0: button = LDL_MouseButtonLeft;   break;
        case 1: button = LDL_MouseButtonRight;  break;
        case 2: button = LDL_MouseButtonMiddle; break;
        default: return;
    }

    LDL_Event report;
    report.Type           = LDL_EventIsMouseClick;
    report.u.Mouse.State  = state;
    report.u.Mouse.Button = button;
    report.u.Mouse.PosX   = (size_t)pos.x;
    report.u.Mouse.PosY   = (size_t)([self bounds].size.height - pos.y);
    LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
}

- (void)mouseDown:(NSEvent*)event      { [self LDL_handleMouseButton:event state:LDL_ButtonStatePressed];  }
- (void)mouseUp:(NSEvent*)event        { [self LDL_handleMouseButton:event state:LDL_ButtonStateReleased]; }
- (void)rightMouseDown:(NSEvent*)event { [self LDL_handleMouseButton:event state:LDL_ButtonStatePressed];  }
- (void)rightMouseUp:(NSEvent*)event   { [self LDL_handleMouseButton:event state:LDL_ButtonStateReleased]; }
- (void)otherMouseDown:(NSEvent*)event { [self LDL_handleMouseButton:event state:LDL_ButtonStatePressed];  }
- (void)otherMouseUp:(NSEvent*)event   { [self LDL_handleMouseButton:event state:LDL_ButtonStateReleased]; }

- (void)LDL_handleKey:(NSEvent*)event state:(size_t)state
{
    uint32_t keyCode = (uint32_t)[event keyCode];
    uint8_t  mapped  = LDL_KeyMapperConvertKey(&mainWindow->KeyMapper, keyCode);

    LDL_Event report;
    report.Type                = LDL_EventIsKeyboard;
    report.u.Keyboard.State    = state;
    report.u.Keyboard.Key      = mapped;
    LDL_EventHandlerPush(&mainWindow->EventHandler, &report);
}

- (void)keyDown:(NSEvent*)event { [self LDL_handleKey:event state:LDL_ButtonStatePressed];  }
- (void)keyUp:(NSEvent*)event   { [self LDL_handleKey:event state:LDL_ButtonStateReleased]; }

@end

// C interface
void LDL_MainWindowInit(LDL_MainWindow* mainWindow, LDL_Result* result,
                        LDL_Vec2i pos, LDL_Vec2i size,
                        const char* title, size_t mode)
{
    if (!mainWindow || !result)
        return;

    LDL_KeyMapperInit(&mainWindow->KeyMapper);
    LDL_EventHandlerInit(&mainWindow->EventHandler);
    LDL_BaseWindowInit(&mainWindow->BaseWindow, pos, size, title, mode);

    NSApplication* app = [NSApplication sharedApplication];
    [app setActivationPolicy:NSApplicationActivationPolicyRegular];
    [app finishLaunching];
    mainWindow->NSApp = (void*)app;

    NSRect frame = NSMakeRect((CGFloat)pos.x,  (CGFloat)pos.y,
                              (CGFloat)size.x, (CGFloat)size.y);

    NSUInteger styleMask = NSWindowStyleMaskTitled
                         | NSWindowStyleMaskClosable
                         | NSWindowStyleMaskResizable
                         | NSWindowStyleMaskMiniaturizable;

    NSWindow* window = [[NSWindow alloc] initWithContentRect:frame
                                                   styleMask:styleMask
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];
    if (!window)
    {
        LDL_ResultAddMessage(result, "Error: NSWindow alloc\n");
        return;
    }

    mainWindow->Window = (void*)window;

    LDL_WindowDelegate* delegate = [[LDL_WindowDelegate alloc] init];
    delegate->mainWindow = mainWindow;
    [window setDelegate:delegate];
    mainWindow->WindowDelegate = (void*)delegate;

    NSRect contentFrame = [[window contentView] frame];

    LDL_ContentView* view = [[LDL_ContentView alloc] initWithFrame:contentFrame];
    view->mainWindow = mainWindow;

    [window setContentView:view];
    [window makeFirstResponder:view];
    mainWindow->View = (void*)view;

    NSString* nsTitle = [NSString stringWithUTF8String:
                            LDL_BaseWindowGetTitle(&mainWindow->BaseWindow)];
    [window setTitle:nsTitle];

    [window makeKeyAndOrderFront:nil];
    [app activateIgnoringOtherApps:YES];

    [window setAcceptsMouseMovedEvents:YES];
}

void LDL_MainWindowDeinit(LDL_MainWindow* mainWindow)
{
    if (!mainWindow)
        return;

    if (mainWindow->Window)
    {
        NSWindow* window = (NSWindow*)mainWindow->Window;
        [window setDelegate:nil];
        [window close];
        mainWindow->Window = NULL;
    }

    if (mainWindow->WindowDelegate)
    {
        LDL_WindowDelegate* delegate = (LDL_WindowDelegate*)mainWindow->WindowDelegate;
        [delegate release];
        mainWindow->WindowDelegate = NULL;
    }

    if (mainWindow->View)
    {
        LDL_ContentView* view = (LDL_ContentView*)mainWindow->View;
        [view release];
        mainWindow->View = NULL;
    }

    while (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
    {
        LDL_Event event;
        LDL_EventHandlerPop(&mainWindow->EventHandler, &event);
    }
}

LDL_Vec2i LDL_MainWindowGetPos(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_BaseWindowGetPos(&mainWindow->BaseWindow);

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_MainWindowGetSize(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_BaseWindowGetSize(&mainWindow->BaseWindow);

    return LDL_GetVec2i(0, 0);
}

const char* LDL_MainWindowGetTitle(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_BaseWindowGetTitle(&mainWindow->BaseWindow);

    return NULL;
}

void LDL_MainWindowSetTitle(LDL_MainWindow* mainWindow, const char* title)
{
    if (!mainWindow || !title)
        return;

    LDL_BaseWindowSetTitle(&mainWindow->BaseWindow, title);

    if (mainWindow->Window)
    {
        NSWindow*  window  = (NSWindow*)mainWindow->Window;
        NSString*  nsTitle = [NSString stringWithUTF8String:
                                LDL_BaseWindowGetTitle(&mainWindow->BaseWindow)];
        [window setTitle:nsTitle];
    }
}

void LDL_MainWindowPollEvents(LDL_MainWindow* mainWindow)
{
    if (!mainWindow || !mainWindow->NSApp)
        return;

    NSApplication* app = (NSApplication*)mainWindow->NSApp;

    for (;;)
    {
        NSEvent* event = [app nextEventMatchingMask:NSEventMaskAny
                                         untilDate:[NSDate distantPast]
                                            inMode:NSDefaultRunLoopMode
                                           dequeue:YES];
        if (!event)
            break;

        [app sendEvent:event];
    }
}

bool LDL_MainWindowGetEvent(LDL_MainWindow* mainWindow, LDL_Event* event)
{
    if (!mainWindow || !event)
        return false;

    LDL_MainWindowPollEvents(mainWindow);

    if (!LDL_EventHandlerEmpty(&mainWindow->EventHandler))
        return LDL_EventHandlerPop(&mainWindow->EventHandler, event);

    return false;
}

void LDL_MainWindowStopEvent(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        LDL_EventHandlerStop(&mainWindow->EventHandler);
}

bool LDL_MainWindowIsRunning(LDL_MainWindow* mainWindow)
{
    if (mainWindow)
        return LDL_EventHandlerRunning(&mainWindow->EventHandler);

    return false;
}
