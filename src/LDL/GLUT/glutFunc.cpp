// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/GLUT/glutApp.hpp>
#include <LDL/GLUT/glutFunc.hpp>

void glutInit(int* argc, char** argv)
{
	App().Init(argc, argv);
}

void glutMainLoop()
{
	App().MainLoop();
}

void glutInitWindowPosition(int x, int y)
{
	LDL_UNUSED(x);
	LDL_UNUSED(y);
}

void glutInitWindowSize(int width, int height)
{
	App().InitWindowSize(LDL_Vec2u(width, height));
}

int glutCreateWindow(const char* title)
{
	return App().CreateWindow(title);
}

void glutDisplayFunc(void(*func)())
{
	App().DisplayFunc(func);
}

void glutReshapeFunc(void(*func)(int, int))
{
	App().ReshapeFunc(func);
}
