// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/New.hpp>
#include <LDL/Core/StdFuncs.hpp>
#include <LDL/APIs/OpenGL/OpenGL_Loader.hpp>
#include <LDL/APIs/GLUT/glutApplication.hpp>

using namespace LDL;

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
	_window->~Window();
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

void glutApplication::InitWindowPos(const Vec2u& pos)
{
	_pos = pos;
}

void glutApplication::InitWindowSize(const Vec2u& size)
{
	_size = size;
}

int glutApplication::CreateWindow(const char* title)
{
	RenderContext renderContext(RenderMode::OpenGL1);

	void* memory = LDL_malloc(sizeof(Window));

	_window = new(memory) Window(_result, renderContext, _pos, _size, title);

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
	Event report;

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
