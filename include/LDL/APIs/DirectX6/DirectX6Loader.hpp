#ifndef LDL_APIs_DirectX6_DirectX6Loader_hpp
#define LDL_APIs_DirectX6_DirectX6Loader_hpp

#include <LDL/Core/Library.hpp>
#include <LDL/APIs/DirectX6/d3d.hpp>

namespace LDL
{
	namespace DirectX6
	{
		class LDL_LIBRARY DirectX6Loader
		{
		public:
			DirectX6Loader();
		private:
			Library _ddraw;
		};
	}
}

#endif