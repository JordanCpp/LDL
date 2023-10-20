#include "RenderContextImplOpenGL1.hpp"

using namespace LDL::Graphics;

RenderContextImplOpenGL1::RenderContextImplOpenGL1(size_t mode) :
	_Mode(mode)
{
}

size_t RenderContextImplOpenGL1::Mode()
{
	return _Mode;
}

