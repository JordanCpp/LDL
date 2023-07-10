#ifndef LDL_Graphics_Software_RenderImpl_hpp
#define LDL_Graphics_Software_RenderImpl_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Window.hpp>
#include "TextureImplSoftware.hpp"
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/PixelPainter.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/ImageResizer.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>
#include "../RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImplSoftware : public RenderImpl
		{
		public:
			RenderImplSoftware(RenderContextImpl* renderContextImpl, Window* window);
			void Buffer(uint8_t * dst);
			void Begin();
			void End();
			const Math::Vec2u& Size();
			const LDL::Graphics::Color& Color();
			void Clear();
			void Color(const LDL::Graphics::Color& color);
			void Pixel(const Math::Vec2u& pos);
			void Fill(const Math::Vec2u& pos, const Math::Vec2u& size);
			void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(TextureBatcher* textureBatcher);
		private:
			Window* _Window;
			Surface _Canvas;
			PixelPainter _PixelPainter;
			PixelCopier _PixelCopier;
			ImageResizer _ImageResizer;
		};
	}
}

#endif    