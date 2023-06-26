#ifndef LDL_Graphics_RenderImpl_hpp
#define LDL_Graphics_RenderImpl_hpp

#include <LDL/Graphics/Texture.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/TextureBatcher.hpp>

namespace LDL
{
	namespace Graphics
	{
		class RenderImpl
		{
		public:
			virtual void Buffer(uint8_t* dst) = 0;
			virtual void Begin() = 0;
			virtual void End() = 0;
			virtual const Math::Vec2u& Size() = 0;
			virtual const LDL::Graphics::Color& Color() = 0;
			virtual void Clear() = 0;
			virtual void Color(const LDL::Graphics::Color& color) = 0;
			virtual void Pixel(const Math::Vec2u& pos) = 0;
			virtual void Fill(const Math::Vec2u& pos, const Math::Vec2u& size) = 0;
			virtual void Line(const Math::Vec2u& pos1, const Math::Vec2u& pos2) = 0;
			virtual void Draw(Texture* image, const Math::Vec2u& pos) = 0;
			virtual void Draw(Texture* image, const Math::Vec2u& pos, const Math::Vec2u& size) = 0;
			virtual void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize) = 0;
			virtual void Draw(Texture* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize) = 0;
			virtual void Draw(Surface* image, const Math::Vec2u& pos) = 0;
			virtual void Draw(Surface* image, const Math::Vec2u& pos, const Math::Vec2u& size) = 0;
			virtual void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize) = 0;
			virtual void Draw(Surface* image, const Math::Vec2u& dstPos, const Math::Vec2u& dstSize, const Math::Vec2u& srcPos, const Math::Vec2u& srcSize) = 0;
			virtual void Draw(TextureBatcher* textureBatcher) = 0;
		private:
		};
	}
}

#endif    