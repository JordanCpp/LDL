#include "CameraImplSoftware.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImplSoftware::CameraImplSoftware(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_RenderImpl(renderImpl),
	_Pos(pos),
	_Size(size)
{
}

const Vec2u& CameraImplSoftware::Pos()
{
	return _Pos;
}

const Vec2u& CameraImplSoftware::Size()
{
	return _Size;
}

void CameraImplSoftware::Pos(const Vec2u& pos)
{
}

void CameraImplSoftware::Size(const Vec2u& size)
{
}