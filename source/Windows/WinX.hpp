#ifndef LDL_Windows_WinX_hpp
#define LDL_Windows_WinX_hpp

#define  STRICT

#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
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

#endif