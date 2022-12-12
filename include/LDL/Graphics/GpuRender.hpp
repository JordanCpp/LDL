#ifndef LDL_Graphics_GpuRender_hpp
#define LDL_Graphics_GpuRender_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Cpu/CpuImage.hpp>
#include <LDL/Graphics/GpuWindow.hpp>
#include <LDL/Graphics/IGpuImage.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GpuRenderImpl;

		class GpuRender: public LDL::Core::FastPimpl
		{
		public:
			GpuRender(LDL::Graphics::GpuWindow* window);
			~GpuRender();
			void Begin();
			void End();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const LDL::Graphics::Point2u& pos);
			void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2);
			void Draw(LDL::Graphics::IGpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::IGpuImage* image, const LDL::Graphics::Point2u& pos);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos);
		private:
			GpuRenderImpl* _GpuRenderImpl;
		};
	}
}

#endif 