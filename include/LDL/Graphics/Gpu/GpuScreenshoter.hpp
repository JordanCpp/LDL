#ifndef LDL_Graphics_GpuScreenshoter_hpp
#define LDL_Graphics_GpuScreenshoter_hpp

#include <LDL/Graphics/Gpu/GpuRender.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuScreenshoterImpl;

		class GpuScreenshoter : public LDL::Core::FastPimpl
		{
		public:
			GpuScreenshoter(const std::string& path, const std::string& name, LDL::Graphics::GpuRender* render, LDL::Graphics::CpuImage* image);
			~GpuScreenshoter();
			void Shot();
		private:
			GpuScreenshoterImpl* _GpuScreenshoterImpl;
		};
	}
}

#endif  