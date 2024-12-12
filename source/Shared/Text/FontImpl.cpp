#include "FontImpl.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL::Core;
using namespace LDL::Text;

FontImpl::FontImpl(RasterizerContextImpl* rasterizerContextImpl, size_t fontSize, uint8_t* font, size_t size) :
	_Face(NULL)
{
	FT_Error error = FT_New_Memory_Face(rasterizerContextImpl->GetLibrary(), font, (FT_Long)size, 0, &_Face);
	LDL_ASSERT_DETAIL(error == 0, "FT_Init_FreeType failed");

	error = FT_Set_Pixel_Sizes(_Face, 0, (FT_Long)fontSize);
	LDL_ASSERT_DETAIL(error == 0, "FT_Set_Pixel_Sizes failed");
}

FontImpl::~FontImpl()
{
	FT_Done_Face(_Face);
}

FT_Face FontImpl::GetFace()
{
	return _Face;
}
