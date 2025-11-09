// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_APIs_GLUT_glut_h
#define LDL_APIs_GLUT_glut_h

#include <LDL/APIs/GLUT/glut_config.h>

#ifdef __cplusplus
extern "C" {
#endif 

GLUT_DECLSPEC void GLUTCALL glutMainLoop();
GLUT_DECLSPEC void GLUTCALL glutInitWindowPosition(int x, int y);
GLUT_DECLSPEC void GLUTCALL glutInitWindowSize(int width, int height);
GLUT_DECLSPEC int  GLUTCALL glutCreateWindow(const char* title);
GLUT_DECLSPEC void GLUTCALL glutDisplayFunc(void (*func)(void));
GLUT_DECLSPEC void GLUTCALL glutReshapeFunc(void (*func)(int, int));

#ifdef __cplusplus
}
#endif

#endif
