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
#import <OpenGL/OpenGL.h>
#include <LDL/macOS/WinGL.h>

@interface LDL_OpenGLView : NSOpenGLView
{
@public
    LDL_WindowOpenGL* glWindow;
}
@end

@implementation LDL_OpenGLView

- (BOOL)acceptsFirstResponder { return YES; }
- (BOOL)canBecomeKeyView      { return YES; }

// Flip coordinate system so (0,0) is top-left, matching X11 behaviour 
- (BOOL)isFlipped { return YES; }

- (void)LDL_pushMouseMove:(NSEvent*)event
{
    NSPoint pos = [self convertPoint:[event locationInWindow] fromView:nil];

    LDL_Event report;
    report.Type         = LDL_EventIsMouseMove;
    report.u.Mouse.PosX = (size_t)pos.x;
    report.u.Mouse.PosY = (size_t)([self bounds].size.height - pos.y);
    LDL_EventHandlerPush(&glWindow->MainWindow.EventHandler, &report);
}

- (void)mouseMoved:(NSEvent*)event       { [self LDL_pushMouseMove:event]; }
- (void)mouseDragged:(NSEvent*)event     { [self LDL_pushMouseMove:event]; }
- (void)rightMouseDragged:(NSEvent*)event { [self LDL_pushMouseMove:event]; }
- (void)otherMouseDragged:(NSEvent*)event { [self LDL_pushMouseMove:event]; }

- (void)LDL_pushMouseButton:(NSEvent*)event state:(size_t)state
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
    LDL_EventHandlerPush(&glWindow->MainWindow.EventHandler, &report);
}

- (void)mouseDown:(NSEvent*)event      { [self LDL_pushMouseButton:event state:LDL_ButtonStatePressed];  }
- (void)mouseUp:(NSEvent*)event        { [self LDL_pushMouseButton:event state:LDL_ButtonStateReleased]; }
- (void)rightMouseDown:(NSEvent*)event { [self LDL_pushMouseButton:event state:LDL_ButtonStatePressed];  }
- (void)rightMouseUp:(NSEvent*)event   { [self LDL_pushMouseButton:event state:LDL_ButtonStateReleased]; }
- (void)otherMouseDown:(NSEvent*)event { [self LDL_pushMouseButton:event state:LDL_ButtonStatePressed];  }
- (void)otherMouseUp:(NSEvent*)event   { [self LDL_pushMouseButton:event state:LDL_ButtonStateReleased]; }

- (void)LDL_pushKey:(NSEvent*)event state:(size_t)state
{
    uint32_t keyCode = (uint32_t)[event keyCode];
    uint8_t  mapped  = LDL_KeyMapperConvertKey(&glWindow->MainWindow.KeyMapper, keyCode);

    LDL_Event report;
    report.Type             = LDL_EventIsKeyboard;
    report.u.Keyboard.State = state;
    report.u.Keyboard.Key   = mapped;
    LDL_EventHandlerPush(&glWindow->MainWindow.EventHandler, &report);
}

- (void)keyDown:(NSEvent*)event { [self LDL_pushKey:event state:LDL_ButtonStatePressed];  }
- (void)keyUp:(NSEvent*)event   { [self LDL_pushKey:event state:LDL_ButtonStateReleased]; }

- (void)reshape
{
    [super reshape];

    NSRect frame = [self bounds];

    LDL_Event report;
    report.Type            = LDL_EventIsResize;
    report.u.Resize.Width  = (size_t)frame.size.width;
    report.u.Resize.Height = (size_t)frame.size.height;
    LDL_EventHandlerPush(&glWindow->MainWindow.EventHandler, &report);
}

@end

// C interface

void LDL_WindowOpenGLInit(LDL_WindowOpenGL* window, LDL_Result* result,
                          LDL_Vec2i pos, LDL_Vec2i size,
                          const char* title, size_t mode)
{
    if (!window || !result)
        return;

    window->Result      = result;
    window->PixelFormat = NULL;
    window->Context     = NULL;

    LDL_MainWindowInit(&window->MainWindow, result, pos, size, title, mode);

    if (!LDL_ResultIsOk(result))
        return;

    NSOpenGLPixelFormatAttribute profile =
        (mode == LDL_ContextOpenGLModern)
            ? NSOpenGLProfileVersion3_2Core
            : NSOpenGLProfileVersionLegacy;

    NSOpenGLPixelFormatAttribute attrs[] =
    {
        NSOpenGLPFAOpenGLProfile, profile,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFADepthSize,   24,
        NSOpenGLPFAStencilSize,  8,
        NSOpenGLPFAColorSize,   32,
        NSOpenGLPFAAccelerated,
        0
    };

    NSOpenGLPixelFormat* pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
    if (!pixelFormat)
    {
        LDL_ResultAddMessage(result, "Error: NSOpenGLPixelFormat\n");
        return;
    }

    window->PixelFormat = (void*)pixelFormat;

    NSOpenGLContext* context = [[NSOpenGLContext alloc] initWithFormat:pixelFormat
                                                          shareContext:nil];
    if (!context)
    {
        LDL_ResultAddMessage(result, "Error: NSOpenGLContext\n");
        return;
    }

    window->Context = (void*)context;

    NSWindow* nsWindow = (NSWindow*)window->MainWindow.Window;

    NSRect contentFrame = [[nsWindow contentView] frame];

    LDL_OpenGLView* glView = [[LDL_OpenGLView alloc] initWithFrame:contentFrame
                                                        pixelFormat:pixelFormat];
    if (!glView)
    {
        LDL_ResultAddMessage(result, "Error: LDL_OpenGLView alloc\n");
        return;
    }

    glView->glWindow = window;

    [glView setOpenGLContext:context];
    [context setView:glView];

    [nsWindow setContentView:glView];
    [nsWindow makeFirstResponder:glView];

    if (window->MainWindow.View)
    {
        [(id)window->MainWindow.View release];
        window->MainWindow.View = (void*)glView;
    }

    [context makeCurrentContext];

    GLint swapInterval = 1;
    [context setValues:&swapInterval
          forParameter:NSOpenGLContextParameterSwapInterval];

    [nsWindow setAcceptsMouseMovedEvents:YES];
}

void LDL_WindowOpenGLDeinit(LDL_WindowOpenGL* window)
{
    if (!window)
        return;

    if (window->Context)
    {
        NSOpenGLContext* context = (NSOpenGLContext*)window->Context;
        [NSOpenGLContext clearCurrentContext];
        [context clearDrawable];
        [context release];
        window->Context = NULL;
    }

    if (window->PixelFormat)
    {
        NSOpenGLPixelFormat* pf = (NSOpenGLPixelFormat*)window->PixelFormat;
        [pf release];
        window->PixelFormat = NULL;
    }

    LDL_MainWindowDeinit(&window->MainWindow);
}

LDL_Vec2i LDL_WindowOpenGLGetPos(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowGetPos(&window->MainWindow);

    return LDL_GetVec2i(0, 0);
}

LDL_Vec2i LDL_WindowOpenGLGetSize(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowGetSize(&window->MainWindow);

    return LDL_GetVec2i(0, 0);
}

bool LDL_WindowOpenGLGetEvent(LDL_WindowOpenGL* window, LDL_Event* event)
{
    if (window && event)
        return LDL_MainWindowGetEvent(&window->MainWindow, event);

    return false;
}

void LDL_WindowOpenGLStopEvent(LDL_WindowOpenGL* window)
{
    if (window)
        LDL_MainWindowStopEvent(&window->MainWindow);
}

bool LDL_WindowOpenGLIsRunning(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowIsRunning(&window->MainWindow);

    return false;
}

const char* LDL_WindowOpenGLGetTitle(LDL_WindowOpenGL* window)
{
    if (window)
        return LDL_MainWindowGetTitle(&window->MainWindow);

    return NULL;
}

void LDL_WindowOpenGLSetTitle(LDL_WindowOpenGL* window, const char* title)
{
    if (window && title)
        LDL_MainWindowSetTitle(&window->MainWindow, title);
}

void LDL_WindowOpenGLPresent(LDL_WindowOpenGL* window)
{
    if (window && window->Context)
    {
        NSOpenGLContext* context = (NSOpenGLContext*)window->Context;
        [context flushBuffer];
    }
}
