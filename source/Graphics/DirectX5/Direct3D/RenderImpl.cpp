#include "RenderImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../../../Platforms/Windows/Graphics/DirectX5/Direct3D/WindowImpl.hpp"

using namespace LDL::Graphics;

RenderImpl::RenderImpl(Window* window) :
	_Window(window),
	_BaseRender(_Window->Size())
{
	HRESULT result;

	result = Direct3DRMCreate(&_Direct3Drm);

	if (FAILED(result))
		throw LDL::Core::RuntimeError("Direct3DRMCreate failed");

	result = DirectDrawCreateClipper(0, &_DirectDrawClipper, NULL);

	if (FAILED(result))
		throw LDL::Core::RuntimeError("DirectDrawCreateClipper failed");

	result = _DirectDrawClipper->SetHWnd(NULL, _Window->GetWindowImpl()->Hwnd());

	if (FAILED(result))
		throw LDL::Core::RuntimeError("SetHWnd failed");

	result = _Direct3Drm->CreateDeviceFromClipper(_DirectDrawClipper, _GUID, (int)_Window->Size().PosX(), (int)_Window->Size().PosY(), &_Direct3DrmDevice);

	if (FAILED(result))
		throw LDL::Core::RuntimeError("CreateDeviceFromClipper failed");
}

RenderImpl::~RenderImpl()
{
	if (_Direct3DrmDevice)
	{
		_Direct3DrmDevice->Release();
		_Direct3DrmDevice = NULL;
	}

	if (_DirectDrawClipper)
	{
		_DirectDrawClipper->Release();
		_DirectDrawClipper = NULL;
	}

	if (_Direct3Drm)
	{
		_Direct3Drm->Release();
		_Direct3Drm = NULL;
	}
}

void RenderImpl::Buffer(uint8_t* dst)
{

}

void RenderImpl::Begin()
{
}

void RenderImpl::End()
{
}

const Point2u& RenderImpl::Size()
{
	return _BaseRender.Size();
}

const LDL::Graphics::Color& LDL::Graphics::RenderImpl::Color()
{
	return _BaseRender.Color();
}

void LDL::Graphics::RenderImpl::Clear()
{
}

void LDL::Graphics::RenderImpl::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void RenderImpl::Pixel(const Point2u& pos)
{
}

void RenderImpl::Line(const Point2u& pos1, const Point2u& pos2)
{
}

void RenderImpl::Fill(const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void RenderImpl::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
}

void RenderImpl::Draw(Surface* image, const Point2u& pos)
{
}

void RenderImpl::Draw(Texture* image, const Point2u& dstPos, const Point2u& srcPos, const Point2u& srcSize)
{
}