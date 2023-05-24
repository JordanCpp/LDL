#include "CameraImpl.hpp"
#include <LDL/Math/Vec3f.hpp>
#include <LDL/Math/Funcs.hpp>

using namespace LDL::Graphics;
using namespace LDL::Math;

CameraImpl::CameraImpl(RenderImpl* renderImpl, const Point2u& pos, const Point2u& size) :
	_RenderImpl(renderImpl),
	_Pos(pos),
	_Size(size)
{
}

const Point2u& CameraImpl::Pos()
{
	return _Pos;
}

const Point2u& CameraImpl::Size()
{
	return _Size;
}

void CameraImpl::Pos(const Point2u& pos)
{
}

void CameraImpl::Size(const Point2u& size)
{
}