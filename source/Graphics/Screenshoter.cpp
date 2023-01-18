#include <LDL/Graphics/Screenshoter.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/ScreenshoterImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/ScreenshoterImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX1
#include "DirectDraw/ScreenshoterImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX5
#include "DirectX5/Direct3D/ScreenshoterImpl.hpp"
#elif LDL_GPU_SUPPORT_DIRECTX9
#include "DirectX9/Direct3D/ScreenshoterImpl.hpp"
#endif

using namespace LDL::Graphics;

Screenshoter::Screenshoter(const std::string& path, const std::string& name, Render* render, Surface* image) :
	_ScreenshoterImpl(new ScreenshoterImpl(path, name, render, image))
{
}

Screenshoter::~Screenshoter()
{
	delete _ScreenshoterImpl;
}

void Screenshoter::Shot()
{
	_ScreenshoterImpl->Shot();
}