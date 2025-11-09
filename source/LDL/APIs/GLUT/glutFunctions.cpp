// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/APIs/GLUT/glutApplication.hpp>
#include <LDL/APIs/GLUT/glutFunctions.hpp>

using namespace LDL;

void glutMainLoop()
{
	App().MainLoop();
}

void glutInitWindowPosition(int x, int y)
{
}

void glutInitWindowSize(int width, int height)
{
	App().InitWindowSize(Vec2u(width, height));
}

int glutCreateWindow(const char* title)
{
	return App().CreateWindow(title);
}

void glutDisplayFunc(void(*func)(void))
{
	App().DisplayFunc(func);
}

void glutReshapeFunc(void(*func)(int, int))
{
	App().ReshapeFunc(func);
}
