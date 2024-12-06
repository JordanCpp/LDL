#ifndef LDL_Graphics_Renders_Glide_RenderImplGlide_hpp
#define LDL_Graphics_Renders_Glide_RenderImplGlide_hpp

#include "../../Base/BaseRender.hpp"
#include <LDL/Graphics/Window.hpp>
#include "TextureImplGlide.hpp"
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>
#include "../../Impls/RenderImpl.hpp"
#include <LDL/APIs/Glide/GlideLoader.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImplGlide : public RenderImpl
		{
		public:
			RenderImplGlide(RenderContextImpl* renderContextImpl, Window* window);
			~RenderImplGlide();
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
			LDL::Glide::GlideLoader _GlideLoader;
			Window* _Window;
			LDL::Graphics::Color _Color;
			RenderContextImpl* _RenderContextImpl;
		};
	}
}

#endif    
