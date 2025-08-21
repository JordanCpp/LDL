#include <LDL/Graphics/ScreenShotter.hpp>
#include "Renders/OpenGL1/ScreenshoterImplOpenGL1.hpp"

using namespace LDL::Graphics;

ScreenShotter::ScreenShotter(const std::string& path, const std::string& name, Render* render, Surface* image)
{
	_impl = new ScreenShotterImplOpenGL1(path, name, render, image);
}

ScreenShotter::~ScreenShotter()
{
	delete _impl;
}

void ScreenShotter::Shot()
{
	_impl->Shot();
}
