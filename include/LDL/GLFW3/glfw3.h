// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLFW3_glfw3_h
#define LDL_GLFW3_glfw3_h

#include <LDL/GLFW3/config.h>

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct GLFWwindow  GLFWwindow;
typedef struct GLFWmonitor GLFWmonitor;

GLFW_DECLSPEC int         GLFWCALL glfwInit(void);
GLFW_DECLSPEC GLFWwindow* GLFWCALL glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
GLFW_DECLSPEC void        GLFWCALL glfwDestroyWindow(GLFWwindow* window);

#ifdef __cplusplus
}
#endif

#endif
