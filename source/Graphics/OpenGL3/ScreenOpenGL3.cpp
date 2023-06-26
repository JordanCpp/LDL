#include "ScreenOpenGL3.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include "../OpenGL/Util.hpp"

using namespace LDL::Graphics;
using namespace LDL::Math;

ScreenOpenGL3::ScreenOpenGL3(const Vec2u& size) :
	_Size(size)
{
}

ScreenOpenGL3::~ScreenOpenGL3()
{
}

void ScreenOpenGL3::Draw(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void ScreenOpenGL3::Draw(Surface* image, const Vec2u& pos)
{
}

void ScreenOpenGL3::DrawTexture(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}

void ScreenOpenGL3::DrawPixels(Surface* image, const Vec2u& pos, const Vec2u& size)
{
}