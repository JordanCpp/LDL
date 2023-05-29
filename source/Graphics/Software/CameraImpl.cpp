#include "CameraImpl.hpp"
#include <LDL/Math/Vec3.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImpl::CameraImpl(RenderImpl* renderImpl, const Vec2u& pos, const Vec2u& size) :
	_RenderImpl(renderImpl),
	_Pos(pos),
	_Size(size)
{
}

const Vec2u& CameraImpl::Pos()
{
	return _Pos;
}

const Vec2u& CameraImpl::Size()
{
	return _Size;
}

void CameraImpl::Pos(const Vec2u& pos)
{
}

void CameraImpl::Size(const Vec2u& size)
{
}