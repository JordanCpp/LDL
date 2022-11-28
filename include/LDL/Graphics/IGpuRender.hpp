#ifndef LDL_Graphics_IGpuRender_hpp
#define LDL_Graphics_IGpuRender_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Graphics/IGpuWindow.hpp>
#include <LDL/Graphics/IGpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class IGpuRender
		{
		public:
			virtual void Begin() = 0;
			virtual void End() = 0;
			virtual const LDL::Graphics::Point2u& Size() = 0;
			virtual const LDL::Graphics::Color& Color() = 0;
			virtual void Clear() = 0;
			virtual void Color(const LDL::Graphics::Color& color) = 0;
			virtual void Pixel(const LDL::Graphics::Point2u& pos) = 0;
			virtual void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size) = 0;
			virtual void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2) = 0;
			virtual void Draw(LDL::Graphics::IGpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size) = 0;
			virtual void Draw(LDL::Graphics::IGpuImage* image, const LDL::Graphics::Point2u& pos) = 0;
			virtual void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size) = 0;
			virtual void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos) = 0;
			virtual ~IGpuRender() {};
		};
	}
}

#endif 