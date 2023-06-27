#include "CameraImplDirect3D9.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImplDirect3D9::CameraImplDirect3D9(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_RenderImpl(renderImpl),
	_Pos(pos),
	_Size(size)
{
}

const Vec2u& CameraImplDirect3D9::Pos()
{
	return _Pos;
}

const Vec2u& CameraImplDirect3D9::Size()
{
	return _Size;
}

void CameraImplDirect3D9::Pos(const Vec2u& pos)
{
}

void CameraImplDirect3D9::Size(const Vec2u& size)
{
}