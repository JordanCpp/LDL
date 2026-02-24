// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Camera_hpp
#define LDL_Graphics_Camera_hpp

#include <LDL/Graphics/Render.hpp>

namespace LDL
{
    class CameraImpl;

    class LDL_LIBRARY Camera
    {
    public:
        Camera(Render* render, const Vec2u& pos, const Vec2u& size);
        CameraImpl* GetCameraImpl();
        const Vec2u& Pos();
        const Vec2u& Size();
        void Pos(const Vec2u& pos);
        void Size(const Vec2u& size);
    private:
        CameraImpl* _impl;
    };
}

#endif
