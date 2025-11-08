// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Shared_APIs_GLUT_glutApplication_hpp
#define LDL_Shared_APIs_GLUT_glutApplication_hpp

#include <LDL/Graphics/Window.hpp>

class glutApplication
{
public:
	glutApplication();
	~glutApplication();
	void InitWindowPos(const LDL::Vec2u& pos);
	void InitWindowSize(const LDL::Vec2u& size);
	int CreateWindow(const char* title);
	void MainLoop();
private:
	LDL::Result  _result;
	LDL::Window* _window;
	LDL::Vec2u   _pos;
	LDL::Vec2u   _size;
};

glutApplication& App();

#endif
