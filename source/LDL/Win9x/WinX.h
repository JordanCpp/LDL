/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_Win9X_WinX_hpp
#define LDL_Win9X_WinX_hpp

#ifdef NOMINMAX
    #include <windows.h>
#else
    #define NOMINMAX
    #include <windows.h>
    #undef NOMINMAX
#endif

#if !defined INVALID_SET_FILE_POINTER
    #define INVALID_SET_FILE_POINTER ((DWORD)-1)
#endif

#if !defined INVALID_ATOM
    #define INVALID_ATOM ((ATOM)0)
#endif

#if !defined INVALID_FILE_ATTRIBUTES
    #define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
#endif

#if !defined VK_OEM_1
    #define VK_OEM_1 0xBA
#endif

#if !defined VK_OEM_2
    #define VK_OEM_2 0xBF
#endif

#if !defined VK_OEM_3
    #define VK_OEM_3 0xC0
#endif

#if !defined VK_OEM_4
    #define VK_OEM_4 0xDB
#endif

#if !defined VK_OEM_5
    #define VK_OEM_5 0xDC
#endif

#if !defined VK_OEM_6
    #define VK_OEM_6 0xDD
#endif

#if !defined VK_OEM_7
    #define VK_OEM_7 0xDE
#endif

#if !defined VK_OEM_PLUS
    #define VK_OEM_PLUS 0xBB
#endif

#if !defined VK_OEM_COMMA
    #define VK_OEM_COMMA 0xBC
#endif

#if !defined VK_OEM_MINUS
    #define VK_OEM_MINUS 0xBD
#endif

#if !defined VK_OEM_PERIOD
    #define VK_OEM_PERIOD 0xBE
#endif

#if !defined WM_MOUSEWHEEL
    #define WM_MOUSEWHEEL 0x020A
#endif

#if !defined WM_MOUSEHWHEEL
    #define WM_MOUSEHWHEEL 0x020E
#endif

#ifndef GET_WHEEL_DELTA_WPARAM
    #define GET_WHEEL_DELTA_WPARAM(wParam) ((short)HIWORD(wParam))
#endif

#endif
