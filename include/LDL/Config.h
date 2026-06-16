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

#ifndef LDL_Config_H
#define LDL_Config_H

#if defined(_WIN32)
    #define LDL_EXPORT __declspec(dllexport)
    #define LDL_IMPORT __declspec(dllimport)
#elif defined(__unix__)
    #define LDL_EXPORT __attribute__((visibility("default")))
    #define LDL_IMPORT
#else
    #define LDL_EXPORT
    #define LDL_IMPORT
#endif

#if defined(LDL_STATIC_LIBRARY)
    #define LDL_LIBRARY
#else
    #if defined(LDL_SHARED_LIBRARY)
        #define LDL_LIBRARY LDL_EXPORT
    #else
        #define LDL_LIBRARY LDL_IMPORT
    #endif
#endif

#if defined(_WIN32)
    #define LDL_API_CALL __cdecl
    #define LDL_GL_CALL  __stdcall
#else
    #define LDL_API_CALL
    #define LDL_GL_CALL
#endif

#define LDL_API_ENTRY LDL_LIBRARY extern

#endif
