// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLUT_glutApp_hpp
#define LDL_GLUT_glutApp_hpp

#include <LDL/Window.hpp>
#include <LDL/GLUT/glutMem.hpp>

#if defined(_WIN32)
    #undef CreateWindow
#endif

class glutApplication
{
public:
	glutApplication();
	~glutApplication();
	void Init(int* pargc, char** argv);
	void SwapBuffers();
	void InitWindowPos(const LDL_Vec2u& pos);
	void InitWindowSize(const LDL_Vec2u& size);
	int CreateWindow(const char* title);
	void DisplayFunc(void (*func)(void));
	void ReshapeFunc(void (*func)(int, int));
	void MainLoop();
private:
	glutMemory        _memory;
	LDL_IWindow*      _window;
	void (*_displayFunc)();
	void (*_reshapeFunc)(int, int);
	LDL_Vec2u         _pos;
	LDL_Vec2u         _size;
	LDL_Result        _result;
	LDL_RenderContext _context;
};

glutApplication& App();

#endif
