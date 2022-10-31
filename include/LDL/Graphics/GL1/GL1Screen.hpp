#ifndef LDL_Graphics_GL1Screen_hpp
#define LDL_Graphics_GL1Screen_hpp

#include <LDL/Graphics/Cpu/CpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GL1Screen
		{
		public:
			GL1Screen(const LDL::Graphics::Point2u& size);
			~GL1Screen();
			void LDL::Graphics::GL1Screen::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void LDL::Graphics::GL1Screen::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos);
		private:
			LDL::Graphics::Point2u _Size;
			size_t _Screen;
		};
	}
}

#endif    