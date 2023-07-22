#ifndef LDL_Text_RasterizerImpl_hpp
#define LDL_Text_RasterizerImpl_hpp

#include <LDL/Text/Font.hpp>
#include <LDL/Graphics/Surface.hpp>
#include <LDL/Graphics/PixelCopier.hpp>
#include <LDL/Graphics/PixelConverter.hpp>
#include <string>

namespace LDL
{
	namespace Text
	{
		class LDL_EXPORT RasterizerImpl
		{
		public:
			RasterizerImpl(const Math::Vec2u& bufferSize);
			~RasterizerImpl();
			Graphics::Surface* Result();
			bool RenderText(const std::string& text, Font* font, const Graphics::Color& color);
		private:
			Graphics::PixelConverter _PixelConverter;
			Graphics::PixelCopier    _PixelCopier;
			Graphics::Surface        _SymbolBuffer;
			Graphics::Surface        _TextBuffer;
		};
	}
}

#endif    