#include "RenderContextImplDirect3D6.hpp"

using namespace LDL::Graphics;

RenderContextImplDirect3D6::RenderContextImplDirect3D6(size_t mode) :
	_Mode(mode)
{
}

size_t RenderContextImplDirect3D6::Mode()
{
	return _Mode;
}

