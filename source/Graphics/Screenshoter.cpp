#include <LDL/Graphics/Screenshoter.hpp>

#ifdef LDL_RENDER_SOFTWARE
#include "Software/ScreenshoterImpl.hpp"
#elif LDL_RENDER_GDI
#include "GDI/ScreenshoterImpl.hpp"
#elif LDL_RENDER_OPENGL1
#include "OpenGL1/ScreenshoterImplOpenGL1.hpp"
#elif LDL_RENDER_OPENGL3
#include "OpenGL3/ScreenshoterImpl.hpp"
#elif LDL_RENDER_DIRECT_DRAW
#include "DirectDraw/ScreenshoterImpl.hpp"
#elif LDL_RENDER_DIRECTX5
#include "DirectX5/Direct3D/ScreenshoterImpl.hpp"
#elif LDL_RENDER_DIRECTX9
#include "DirectX9/Direct3D/ScreenshoterImpl.hpp"
#elif LDL_RENDER_DIRECTX10
#include "DirectX10/Direct3D/ScreenshoterImpl.hpp"
#endif

using namespace LDL::Graphics;

Screenshoter::Screenshoter(const std::string& path, const std::string& name, Render* render, Surface* image)
{
	_ScreenshoterImpl = new ScreenshoterImplOpenGL1(path, name, render, image);
}

Screenshoter::~Screenshoter()
{
	delete _ScreenshoterImpl;
}

void Screenshoter::Shot()
{
	_ScreenshoterImpl->Shot();
}