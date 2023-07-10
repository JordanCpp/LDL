#include "RenderContextImplOpenGL3.hpp"

using namespace LDL::Graphics;

RenderContextImplOpenGL3::RenderContextImplOpenGL3(size_t mode) :
	_Mode(mode)
{
}

size_t RenderContextImplOpenGL3::Mode()
{
	return _Mode;
}