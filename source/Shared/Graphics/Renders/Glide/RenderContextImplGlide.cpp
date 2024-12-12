#include "RenderContextImplGlide.hpp"

using namespace LDL::Graphics;

RenderContextImplGlide::RenderContextImplGlide(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplGlide::Mode()
{
	return _mode;
}

