// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_PixelFormat_hpp
#define LDL_Graphics_PixelFormat_hpp

namespace LDL
{
    class PixelFormat
    {
    public:
        enum
        {
            RGBA32,
            BGRA32,
            RGB24,
            BGR24
        };
    };
}

#endif
