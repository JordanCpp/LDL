#ifndef LDL_DirectX_DirectXLoader_hpp
#define LDL_DirectX_DirectXLoader_hpp

#include <LDL/Core/Library.hpp>
#include <LDL/APIs/DirectX/DirectX9.hpp>

namespace LDL
{
	namespace DirectX
	{
		class LDL_LIBRARY DirectXLoader
		{
		public:
			DirectXLoader();
			DirectX9::LPDIRECT3D9 GetDirect3D();
		private:
			Core::Library _Library_d3d9;
		};
	}
}

#endif