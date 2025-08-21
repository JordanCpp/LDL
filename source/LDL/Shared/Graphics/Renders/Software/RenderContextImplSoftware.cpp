#include "RenderContextImplSoftware.hpp"

using namespace LDL::Graphics;

RenderContextImplSoftware::RenderContextImplSoftware(size_t mode) :
	_mode(mode)
{
}

size_t RenderContextImplSoftware::Mode()
{
	return _mode;
}
