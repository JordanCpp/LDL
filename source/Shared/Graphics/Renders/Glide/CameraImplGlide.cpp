#include "CameraImplGlide.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImplGlide::CameraImplGlide(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_RenderImpl(renderImpl),
	_Pos(pos),
	_Size(size)
{
}

const Vec2u& CameraImplGlide::Pos()
{
	return _Pos;
}

const Vec2u& CameraImplGlide::Size()
{
	return _Size;
}

void CameraImplGlide::Pos(const Vec2u& pos)
{
}

void CameraImplGlide::Size(const Vec2u& size)
{
}
