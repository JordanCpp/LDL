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
