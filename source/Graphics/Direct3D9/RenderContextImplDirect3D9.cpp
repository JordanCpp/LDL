#include "RenderContextImplDirect3D9.hpp"

using namespace LDL::Graphics;

RenderContextImplDirect3D9::RenderContextImplDirect3D9(size_t mode) :
	_Mode(mode)
{
}

size_t RenderContextImplDirect3D9::Mode()
{
	return _Mode;
}