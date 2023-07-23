#include <LDL/Text/Font.hpp>
#include "FontImpl.hpp"

using namespace LDL::Core;
using namespace LDL::Text;

Font::Font(RasterizerContext* rasterizerContext,size_t fontSize, uint8_t* font, size_t size) :
	_FontImpl(new FontImpl(rasterizerContext->GetRasterizerContextImpl(), fontSize, font, size))
{
}

Font::~Font()
{
	delete _FontImpl;
}

FontImpl* Font::GetFontImpl()
{
	return _FontImpl;
}
