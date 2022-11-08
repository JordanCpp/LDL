#include <LDL/Graphics/DX5/DX5Render.hpp>
#include <LDL/Core/RuntimeError.hpp>

LDL::Graphics::DX5Render::DX5Render(LDL::Graphics::DX5Window* window) :
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

	result = _DirectDrawClipper->SetHWnd(NULL, _Window->Hwnd());

	if (FAILED(result))
		throw LDL::Core::RuntimeError("SetHWnd failed");

	result = _Direct3Drm->CreateDeviceFromClipper(_DirectDrawClipper, _GUID, _Window->Size().PosX(), _Window->Size().PosY(), &_Direct3DrmDevice);

	if (FAILED(result))
		throw LDL::Core::RuntimeError("CreateDeviceFromClipper failed");
}

LDL::Graphics::DX5Render::~DX5Render()
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

void LDL::Graphics::DX5Render::Begin()
{
}

void LDL::Graphics::DX5Render::End()
{
}

const LDL::Graphics::Point2u& LDL::Graphics::DX5Render::Size()
{
	return _BaseRender.Size();
}

const LDL::Graphics::Color& LDL::Graphics::DX5Render::Color()
{
	return _BaseRender.Color();
}

void LDL::Graphics::DX5Render::Clear()
{
}

void LDL::Graphics::DX5Render::Color(const LDL::Graphics::Color& color)
{
	_BaseRender.Color(color);
}

void LDL::Graphics::DX5Render::Pixel(const LDL::Graphics::Point2u& pos)
{
}

void LDL::Graphics::DX5Render::Line(const LDL::Graphics::Point2u& pos1, const LDL::Graphics::Point2u& pos2)
{
}

void LDL::Graphics::DX5Render::Fill(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
}

void LDL::Graphics::DX5Render::Draw(LDL::Graphics::DX5Image* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{
}

void LDL::Graphics::DX5Render::Draw(LDL::Graphics::DX5Image* image, const LDL::Graphics::Point2u& pos)
{
	Draw(image, pos, image->Size());
}

void LDL::Graphics::DX5Render::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size)
{

}

void LDL::Graphics::DX5Render::Draw(LDL::Graphics::CpuImage* image, const LDL::Graphics::Point2u& pos)
{

}