#ifndef LDL_Graphics_Render_hpp
#define LDL_Graphics_Render_hpp

#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/RenderContext.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl;
		class Texture;

		class LDL_EXPORT Render: public LDL::Core::FastPimpl
		{
		public:
			Render(RenderContext* renderContext, Window* window);
			~Render();
			RenderImpl* GetRenderImpl();
			void Buffer(uint8_t* dst);
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
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize);
			void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size);
			void Draw(Surface* image, const Math::Vec2u& pos);
			void Draw(TextureBatcher* textureBatcher);
		private:
			RenderImpl* _RenderImpl;
		};
	}
}

#endif 