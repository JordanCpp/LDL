#ifndef LDL_Graphics_OpenGL1_RenderImpl_hpp
#define LDL_Graphics_OpenGL1_RenderImpl_hpp

#include "../../Base/BaseRender.hpp"
#include <LDL/Graphics/Window.hpp>
#include "TextureImplOpenGL1.hpp"
#include "ScreenOpenGL1.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>
#include "RenderBufferOpenGL1.hpp"
#include <LDL/Math/Mat4.hpp>
#include "../../Impls/RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImplOpenGL1: public RenderImpl
		{
		public:
			RenderImplOpenGL1(RenderContextImpl* renderContextImpl, Window* window);
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
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& pos);
			void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(TextureBatcher* textureBatcher);
		private:
			Window* _Window;
			ScreenOpenGL1 _Screen;
			LDL::Graphics::Color _Color;
			RenderContextImpl* _RenderContextImpl;
			RenderBuffer _RenderBuffer;
		public:
			LDL::Math::Mat4f _Projection;
			LDL::Math::Mat4f _ModelView;
		};
	}
}

#endif    
