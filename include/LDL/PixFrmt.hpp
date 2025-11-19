// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_PixFrmt_hpp
#define LDL_PixFrmt_hpp

#include <LDL/Config.hpp>
#include <LDL/Types.hpp>

class LDL_PixelFormat
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

LDL_LIBRARY uint8_t LDL_BytesPerPixelFromPixelFormat(size_t pixelFormat);

#endif
