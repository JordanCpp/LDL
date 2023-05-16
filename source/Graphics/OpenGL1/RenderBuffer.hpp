#ifndef LDL_Graphics_OpenGL1_RenderBuffer_hpp
#define LDL_Graphics_OpenGL1_RenderBuffer_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Graphics/Primitives/Color.hpp>
#include <vector>

namespace LDL
{
	namespace Graphics
	{
		class TextureElement
		{
		public:
			uint8_t type;
			uint16_t  textureId;
			uint16_t  textureQuad;
			uint16_t  dstPosX;
			uint16_t  dstPosY;
			uint16_t  dstSizeX;
			uint16_t  dstSizeY;
			uint16_t  srcPosX;
			uint16_t  srcPosY;
			uint16_t  srcSizeX;
			uint16_t  srcSizeY;
		};

		class LineElement
		{
		public:
			uint8_t type;
			uint8_t r;
			uint8_t g;
			uint8_t b;
			uint16_t firstX;
			uint16_t firstY;
			uint16_t lastX;
			uint16_t lastY;
		};

		class FillElement
		{
		public:
			uint8_t type;
			uint8_t r;
			uint8_t g;
			uint8_t b;
			uint16_t posX;
			uint16_t posY;
			uint16_t sizeX;
			uint16_t sizeY;
		};

		class ClearElement
		{
		public:
			uint8_t type;
			uint8_t r;
			uint8_t g;
			uint8_t b;
		};

		class RenderElement
		{
		public:
			enum
			{
				IsTexture,
				IsLine,
				IsFill,
				IsClear
			};

			uint8_t type;
			
			union
			{
				TextureElement textureElement;
				LineElement    lineElement;
				FillElement    fillElement;
				ClearElement   clearElement;
			};
		};

		class RenderBuffer
		{
		public:
			RenderBuffer();
			void Reset();
			void Texture(const Point2u& dstPos, const Point2u& dstSize, const Point2u& srcPos, const Point2u& srcSize, size_t textureId, size_t textureQuad);
			void Line(const Point2u& first, const Point2u& last, const Color& color);
			void Fill(const Point2u& pos, const Point2u& size, const Color& color);
			void Clear(const Color& color);
			void Draw();
			void Draw(TextureElement & src);
			void Draw(LineElement& src);
			void Draw(FillElement& src);
			void Draw(ClearElement& src);
		private:
			std::vector<RenderElement> _Elements;
		};
	}
}

#endif    