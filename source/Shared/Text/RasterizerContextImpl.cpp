#include "RasterizerContextImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>

using namespace LDL::Core;
using namespace LDL::Text;

RasterizerContextImpl::RasterizerContextImpl()
{
	FT_Error error = FT_Init_FreeType(&_Library);

	if (error != 0)
		throw RuntimeError("FT_Init_FreeType failed");
}

RasterizerContextImpl::~RasterizerContextImpl()
{
	FT_Done_FreeType(_Library);
}

FT_Library RasterizerContextImpl::GetLibrary()
{
	return _Library;
}
