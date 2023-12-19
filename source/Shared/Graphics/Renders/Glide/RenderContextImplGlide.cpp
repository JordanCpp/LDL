#include "RenderContextImplGlide.hpp"

using namespace LDL::Graphics;

RenderContextImplGlide::RenderContextImplGlide(size_t mode) :
	_Mode(mode)
{
}

size_t RenderContextImplGlide::Mode()
{
	return _Mode;
}

