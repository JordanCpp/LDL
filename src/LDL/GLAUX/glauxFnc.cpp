// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Ticks.hpp>
#include <LDL/GLAUX/glaux.h>
#include <LDL/GLAUX/glauxApp.hpp>

void auxInitDisplayMode(GLenum mode)
{
}

void auxInitPosition(int x, int y, int w, int h)
{
	App().InitPosition(x, y, w, h);
}

GLenum auxInitWindow(const char* title)
{
	App().InitWindow(title);

	return 0;
}

void auxMainLoop(void(*func)())
{
	App().MainLoop(func);
}

void auxReshapeFunc(void(*func)(GLsizei, GLsizei))
{
	App().ReshapeFunc(func);
}

void auxSleep(size_t ticks)
{
	return LDL_Delay(ticks);
}
