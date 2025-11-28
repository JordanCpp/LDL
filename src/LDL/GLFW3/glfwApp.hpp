// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLFW3_glfwApp_hpp
#define LDL_GLFW3_glfwApp_hpp

#include <LDL/GLFW3/glfw3.h>
#include <LDL/Window.hpp>

class glfwApplication
{
public:
	glfwApplication();
	~glfwApplication();
private:
	LDL_IWindow* _window;
	LDL_Result   _result;
};

#endif
