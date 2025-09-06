// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/TestEqual.hpp>
#include <LDL/Graphics/PixelPainter.hpp>

using namespace LDL;

void InitDefault()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));
}

void InitValue()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));
}

void InitColor()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));
}

void Clear()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));

	PixelPainter painter;
	LDL::Color color(1, 2, 3, 4);

	painter.Clear(surface.Format(), surface.Pixels(), surface.Size(), color);

	for (uint32_t i = 0; i < surface.Size().x; i++)
	{
		for (uint32_t j = 0; j < surface.Size().y; j++)
		{
		}
	}
}

void Fill()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));
}

void Line()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));
}

void Pixel()
{
	Surface surface(PixelFormat::RGBA32, Vec2u(640, 480));
}

int main()
{
	InitDefault();
	InitValue();
	InitColor();
	Clear();
	Pixel();
	Fill();
	Line();

	return 0;
}
