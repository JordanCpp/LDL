// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/New.hpp>
#include <LDL/StdFuncs.hpp>
#include <LDL/OpenGL/GLLoader.hpp>
#include <LDL/GLUT/glutApplication.hpp>
#include <LDL/Window.hpp>

glutApplication::glutApplication() :
	_window(NULL),
	_displayFunc(NULL),
	_reshapeFunc(NULL)
{
	OpenGLLoader loader(_result);
	loader.Init(1, 1);
}

glutApplication::~glutApplication()
{
	LDL_free(_window);
}

void glutApplication::Init(int* argc, char** argv)
{
	LDL_UNUSED(argc);
	LDL_UNUSED(argv);
}

void glutApplication::SwapBuffers()
{
	if (_window)
	{
		_window->Present();
	}
}

void glutApplication::InitWindowPos(const LDL_Vec2u& pos)
{
	_pos = pos;
}

void glutApplication::InitWindowSize(const LDL_Vec2u& size)
{
	_size = size;
}

int glutApplication::CreateWindow(const char* title)
{
	LDL_RenderContext renderContext(LDL_RenderMode::OpenGL1);

	_window = LDL_CreateWindow(_result, renderContext, _pos, _size, title, 0);

	return 0;
}

void glutApplication::DisplayFunc(void(*func)(void))
{
	_displayFunc = func;
}

void glutApplication::ReshapeFunc(void(*func)(int, int))
{
	_reshapeFunc = func;
}

void glutApplication::MainLoop()
{
	LDL_Event report;

	while (_window->Running())
	{
		while (_window->GetEvent(report))
		{
			if (report.Type == IsQuit)
			{
				_window->StopEvent();
			}
			else if (report.Type == IsResize)
			{
				if (_reshapeFunc)
				{
					_reshapeFunc((int)report.Resize.Width, (int)report.Resize.Height);
				}
			}
		}

		if (_displayFunc)
		{
			_displayFunc();
		}

		_window->Present();
	}
}

static glutApplication glutMainApplication;

glutApplication& App()
{
	return glutMainApplication;
}
