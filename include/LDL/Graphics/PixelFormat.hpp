// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelFormat_hpp
#define LDL_Graphics_PixelFormat_hpp

#include <LDL/Config.hpp>
#include <LDL/std/stddef.hpp>
#include <LDL/std/stdint.hpp>

namespace LDL
{
    class PixelFormat
    {
    public:
        enum
        {
            UNKNOWN,
            RGBA32,
            BGRA32,
            RGB24,
            BGR24
        };
    };

    LDL_LIBRARY uint8_t BytesPerPixelFromPixelFormat(size_t pixelFormat);
}

#endif
