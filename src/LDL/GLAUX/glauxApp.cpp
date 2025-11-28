// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/GLAUX/glauxApp.hpp>
#include <LDL/OpenGL/GLLoader.hpp>

glauxApplication::glauxApplication() :
	_window(NULL),
	_context(LDL_RenderMode::OpenGL1),
	_mainProc(NULL),
	_reshapeProc(NULL)
{
	LDL_OpenGLLoader loader(_result);
	loader.Init(1, 2);
}

glauxApplication::~glauxApplication()
{
	if (_window)
	{
		delete _window;
	}
}

void glauxApplication::InitDisplayMode(GLenum mode)
{
}

void glauxApplication::InitPosition(int x, int y, int w, int h)
{
	_pos  = LDL_Vec2u(x, y);
	_size = LDL_Vec2u(w, h);
}

void glauxApplication::InitWindow(const char* title)
{
	_window = LDL_CreateWindow(_result, _context, _pos, _size, title, LDL_WindowMode::Resized);
}

void glauxApplication::MainLoop(void(*func)())
{
	_mainProc = func;

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
				if (_reshapeProc)
				{
					_reshapeProc((GLsizei)report.Resize.Width, (GLsizei)report.Resize.Height);
				}
			}
		}

		if (_mainProc)
		{
			_mainProc();
		}

		_window->Present();
	}
}

void glauxApplication::ReshapeFunc(void(*func)(GLsizei, GLsizei))
{
	_reshapeProc = func;
}

static glauxApplication glauxMainApplication;

glauxApplication& App()
{
	return glauxMainApplication;
}
