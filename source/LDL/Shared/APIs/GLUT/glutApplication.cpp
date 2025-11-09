// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdlib.h>
#include <LDL/Core/MemoryManager.hpp>
#include <LDL/Shared/APIs/GLUT/glutApplication.hpp>

using namespace LDL;

glutApplication::glutApplication() :
	_window(NULL)
{
	MemoryManager::Instance().Functions(malloc, NULL, NULL, free);
}

glutApplication::~glutApplication()
{
	delete _window;
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

	_window = new Window(_result, renderContext, _pos, _size, title);

	return 0;
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
		}

		_window->Present();
	}
}

static glutApplication glutMainApplication;

glutApplication& App()
{
	return glutMainApplication;
}
