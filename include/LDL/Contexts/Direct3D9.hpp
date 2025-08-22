// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Contexts_Direct3D9_hpp
#define LDL_Contexts_Direct3D9_hpp

#include <LDL/DirectX/DirectX9.hpp>

namespace LDL
{
    namespace Contexts
    {
        class Direct3D9
        {
        public:
            DirectX9::LPDIRECT3D9       Direct;
            DirectX9::LPDIRECT3DDEVICE9 Device;
        };
    }
}

#endif
