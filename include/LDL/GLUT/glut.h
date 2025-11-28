// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLUT_glut_h
#define LDL_GLUT_glut_h

#include <LDL/GLUT/config.h>
#include <LDL/OpenGL/GL1_2.hpp>

#ifdef __cplusplus
extern "C" {
#endif 

extern GLUT_DECLSPEC void GLUTCALL glutInit(int* argc, char** argv);
extern GLUT_DECLSPEC void GLUTCALL glutSwapBuffers();
extern GLUT_DECLSPEC void GLUTCALL glutMainLoop();
extern GLUT_DECLSPEC void GLUTCALL glutInitWindowPosition(int x, int y);
extern GLUT_DECLSPEC void GLUTCALL glutInitWindowSize(int width, int height);
extern GLUT_DECLSPEC int  GLUTCALL glutCreateWindow(const char* title);
extern GLUT_DECLSPEC void GLUTCALL glutDisplayFunc(void (*func)());
extern GLUT_DECLSPEC void GLUTCALL glutReshapeFunc(void (*func)(int, int));

#ifdef __cplusplus
}
#endif

#endif
