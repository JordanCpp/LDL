// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_Camera_hpp
#define LDL_Graphics_Camera_hpp

#include <LDL/Graphics/Render.hpp>

namespace LDL
{
    namespace Graphics
    {
        class CameraImpl;

        class LDL_LIBRARY Camera
        {
        public:
            Camera(Render* render, const Math::Vec2u& pos, const Math::Vec2u& size);
            CameraImpl* GetCameraImpl();
            const Math::Vec2u& Pos();
            const Math::Vec2u& Size();
            void Pos(const Math::Vec2u& pos);
            void Size(const Math::Vec2u& size);
        private:
            CameraImpl* _impl;
        };
    }
}

#endif
