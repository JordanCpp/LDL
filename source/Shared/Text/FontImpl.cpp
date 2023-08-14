#include "FontImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;
using namespace LDL::Text;

FontImpl::FontImpl(RasterizerContextImpl* rasterizerContextImpl, size_t fontSize, uint8_t* font, size_t size) :
	_Face(NULL)
{
	FT_Error error = FT_New_Memory_Face(rasterizerContextImpl->GetLibrary(), font, (FT_Long)size, 0, &_Face);

	if (error != 0)
		throw RuntimeError("FT_Init_FreeType failed");

	error = FT_Set_Pixel_Sizes(_Face, 0, (FT_Long)fontSize);

	if (error != 0)
		throw RuntimeError("FT_Set_Pixel_Sizes failed");
}

FontImpl::~FontImpl()
{
	FT_Done_Face(_Face);
}

FT_Face FontImpl::GetFace()
{
	return _Face;
}
