#ifndef LDL_Graphics_Software_RenderImpl_hpp
#define LDL_Graphics_Software_RenderImpl_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Window.hpp>
#include "TextureImpl.hpp"
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/PixelPainter.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/ImageResizer.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			RenderImpl(Window* window);
			void Buffer(uint8_t * dst);
			void Begin();
			void End();
			const Point2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Point2u& pos);
			void Fill(const Point2u& pos, const Point2u& size);
			void Line(const Point2u& pos1, const Point2u& pos2);
			void Draw(Texture* image, const Point2u& pos, const Point2u& size);
			void Draw(Texture* image, const Point2u& pos);
			void Draw(Surface* image, const Point2u& pos, const Point2u& size);
			void Draw(Surface* image, const Point2u& pos);
			void Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize);
		private:
			Window* _Window;
			BaseRender _BaseRender;
			Surface _Canvas;
			PixelPainter _PixelPainter;
			PixelCopier _PixelCopier;
			ImageResizer _ImageResizer;
		};
	}
}

#endif    