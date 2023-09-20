#include "RContext.hpp"

LDL_ImpRenderContext::LDL_ImpRenderContext(size_t mode) :
	_Mode(mode)
{
}

size_t LDL_ImpRenderContext::Mode()
{
	return _Mode;
}
