#ifndef LDL_Graphics_IGpuScreenshoter_hpp
#define LDL_Graphics_IGpuScreenshoter_hpp

#include <LDL/Graphics/IGpuRender.hpp>
#include <LDL/Graphics/Base/BaseScreenshoter.hpp>

namespace LDL
{
	namespace Graphics
	{
		class IGpuScreenshoter
		{
		public:
			virtual void Shot() = 0;
		};
	}
}

#endif  