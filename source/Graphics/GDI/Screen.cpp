#include "Screen.hpp"
#include <LDL/OpenGL/OpenGL1_0.hpp>
#include "Util.hpp"

using namespace LDL::Graphics;

Screen::Screen(const Point2u& size) :
	_Size(size)
{
}

Screen::~Screen()
{
}

void Screen::Draw(Surface* image, const Point2u& pos, const Point2u& size)
{
}

void Screen::Draw(Surface* image, const Point2u& pos)
{
}

void Screen::DrawTexture(Surface* image, const Point2u& pos, const Point2u& size)
{
}

void Screen::DrawPixels(Surface* image, const Point2u& pos, const Point2u& size)
{
}