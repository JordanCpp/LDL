// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLAUX_glauxApp_hpp
#define LDL_GLAUX_glauxApp_hpp

#include <LDL/Window.hpp>
#include <LDL/GLAUX/glaux.h>
#include <LDL/GLAUX/glauxMem.hpp>

class glauxApplication
{
public:
	glauxApplication();
	~glauxApplication();
	void InitDisplayMode(GLenum mode);
	void InitPosition(int x, int y, int w, int h);
	void InitWindow(const char* title);
	void MainLoop(void(*func)());
	void ReshapeFunc(void(*func)(GLsizei, GLsizei));
private:
	glauxMemory       _memory;
	LDL_IWindow*      _window;
	LDL_Vec2u         _pos;
	LDL_Vec2u         _size;
	LDL_RenderContext _context;
	LDL_Result        _result;
	void (*_mainProc)();
	void (*_reshapeProc)(GLsizei, GLsizei);
};

glauxApplication& App();

#endif
