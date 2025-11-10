// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_APIs_GLUT_glutApplication_hpp
#define LDL_Shared_APIs_GLUT_glutApplication_hpp

#include <LDL/Graphics/Window.hpp>
#include <LDL/APIs/GLUT/glutMemory.hpp>

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
	void InitWindowPos(const LDL::Vec2u& pos);
	void InitWindowSize(const LDL::Vec2u& size);
	int CreateWindow(const char* title);
	void DisplayFunc(void (*func)(void));
	void ReshapeFunc(void (*func)(int, int));
	void MainLoop();
private:
	glutMemory   _memory;
	LDL::Window* _window;
	void (*_displayFunc)();
	void (*_reshapeFunc)(int, int);
	LDL::Vec2u   _pos;
	LDL::Vec2u   _size;
	LDL::Result  _result;
};

glutApplication& App();

#endif
