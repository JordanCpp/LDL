#include <LDL/Text/Font.hpp>
#include "FontImpl.hpp"

using namespace LDL::Text;

Font::Font(RasterizerContext* rasterizerContext,size_t fontSize, uint8_t* font, size_t size) :
	_impl(new FontImpl(rasterizerContext->GetRasterizerContextImpl(), fontSize, font, size))
{
}

Font::~Font()
{
	delete _impl;
}

FontImpl* Font::GetFontImpl()
{
	return _impl;
}
