// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLFW3_glfwWin_hpp
#define LDL_GLFW3_glfwWin_hpp

#include <LDL/Window.hpp>
#include <LDL/GLFW3/glfwMntr.hpp>

struct GLFWwindow
{
public:
private:
	LDL_IWindow* _window;
	LDL_Result   _result;
};

#endif
