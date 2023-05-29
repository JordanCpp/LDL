#ifndef LDL_Graphics_GDI_RenderImpl_hpp
#define LDL_Graphics_GDI_RenderImpl_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Window.hpp>
#include "TextureImpl.hpp"
#include "Screen.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <windows.h>
#include <wingdi.h>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			RenderImpl(RenderContextImpl* renderContextImpl, Window* window);
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
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
		private:
			Window* _Window;
			Screen _Screen;
			LDL::Graphics::Color _Color;
			PAINTSTRUCT _PaintStruct;
			HPEN _Pen;
			HBRUSH _Brush;
		};
	}
}

#endif    