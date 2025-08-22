// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Contexts_DirectDrawContext_hpp
#define LDL_Contexts_DirectDrawContext_hpp

#include <ddraw.h>

namespace LDL
{
    namespace Contexts
    {
        class DirectDrawContext
        {
        public:
            LPDIRECTDRAW        _DirectDraw;
            DDSURFACEDESC       _SurfaceDesc;
            DDSCAPS             _SurfaceCaps;
            LPDIRECTDRAWSURFACE _Primary;
            LPDIRECTDRAWSURFACE _Screen;
            LPDIRECTDRAWCLIPPER _DirectDrawClipper;
        };
    }
}

#endif
