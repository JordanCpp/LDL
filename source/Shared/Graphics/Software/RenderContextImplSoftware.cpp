#include "RenderContextImplSoftware.hpp"

using namespace LDL::Graphics;

RenderContextImplSoftware::RenderContextImplSoftware(size_t mode) :
	_Mode(mode)
{
}

size_t RenderContextImplSoftware::Mode()
{
	return _Mode;
}
