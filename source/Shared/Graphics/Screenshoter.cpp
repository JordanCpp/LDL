#include <LDL/Graphics/Screenshoter.hpp>
#include "Renders/OpenGL1/ScreenshoterImplOpenGL1.hpp"

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
