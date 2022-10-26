#ifndef LDL_Graphics_GL1Render_hpp
#define LDL_Graphics_GL1Render_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	namespace Graphics
	{
		class GL1Render
		{
		public:
			GL1Render(LDL::Graphics::GL1Window* window);
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Present();
			void Pixel(const LDL::Graphics::Point2u& pos);
			void Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size);
			void Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2);
		private:
			LDL::Graphics::GL1Window* _Window;
			LDL::Graphics::BaseRender _BaseRender;
		};
	}
}

#endif    