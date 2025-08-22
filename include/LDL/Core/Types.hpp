// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Types_hpp
#define LDL_Core_Types_hpp

#if (_MSC_VER <= 1600 && !__MINGW32__ && !__BORLANDC__)
    #include <LDL/Core/pstdint.h>
#else
    #include <stdint.h>
    #include <stddef.h>
    #include <limits.h>
#endif

#if defined(_WIN32) || defined(WIN32)
    #define LDL_CONFIG_COLOR_BGRA
#endif

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
    #define LDL_API_CALL __stdcall
#elif defined(__unix__)
    #define LDL_API_CALL
#else
    #define LDL_API_CALL
#endif

#define LDL_API_ENTRY LDL_LIBRARY extern

#endif
