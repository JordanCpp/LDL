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
