#ifndef LDL_Graphics_OpenGL3_RenderImpl_hpp
#define LDL_Graphics_OpenGL3_RenderImpl_hpp

#include <LDL/Graphics/Base/BaseRender.hpp>
#include <LDL/Graphics/Window.hpp>
#include "TextureImplOpenGL3.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Math/Mat4.hpp>
#include "LinePainterOpenGL3.hpp"
#include "TexturePainterOpenGL3.hpp"
#include <LDL/Graphics/TextureBatcher.hpp>
#include "../RenderImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class RenderImplOpenGL3 : public RenderImpl
		{
		public:
			RenderImplOpenGL3(RenderContextImpl* renderContextImpl, Window* window);
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
			LDL::Graphics::Color _Color;
			Math::Mat4f projection;
			ShaderLoader _ShaderLoader;
			LinePainter _LinePainter;
			TexturePainter _TexturePainter;
		public:
			Math::Mat4f _Projection;
			Math::Mat4f _ModelView;
		};
	}
}

#endif    
