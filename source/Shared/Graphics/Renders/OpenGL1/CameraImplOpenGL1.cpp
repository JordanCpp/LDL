#include "CameraImplOpenGL1.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImplOpenGL1::CameraImplOpenGL1(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_RenderImpl(renderImpl),
	_Pos(pos),
	_Size(size)
{
}

const Vec2u& CameraImplOpenGL1::Pos()
{
	return _Pos;
}

const Vec2u& CameraImplOpenGL1::Size()
{
	return _Size;
}

void CameraImplOpenGL1::Pos(const Vec2u& pos)
{
	//_RenderImpl->_ModelView = Translate(_RenderImpl->_ModelView, Vec3f((float)pos.x, (float)pos.y, 0.0f));
}

void CameraImplOpenGL1::Size(const Vec2u& size)
{
}
