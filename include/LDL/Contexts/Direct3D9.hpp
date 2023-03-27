#ifndef LDL_Contexts_Direct3D9_hpp
#define LDL_Contexts_Direct3D9_hpp

#include <d3d9.h>

namespace LDL
{
    namespace Contexts
    {
        class Direct3D9
        {
        public:
            IDirect3D9       * Direct;
            IDirect3DDevice9 * Device;
        };
    }
}

#endif