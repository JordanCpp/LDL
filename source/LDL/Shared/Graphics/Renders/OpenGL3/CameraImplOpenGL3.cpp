#include "CameraImplOpenGL3.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImplOpenGL3::CameraImplOpenGL3(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_renderImpl(renderImpl),
	_pos(pos),
	_size(size)
{
}

const Vec2u& CameraImplOpenGL3::Pos()
{
	return _pos;
}

const Vec2u& CameraImplOpenGL3::Size()
{
	return _size;
}

void CameraImplOpenGL3::Pos(const Vec2u& pos)
{
	//_RenderImpl->_ModelView = Translate(_RenderImpl->_ModelView, Vec3f((float)pos.x, (float)pos.y, 0.0f));
}

void CameraImplOpenGL3::Size(const Vec2u& size)
{
}
