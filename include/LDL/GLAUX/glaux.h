// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_GLAUX_glaux_h
#define LDL_GLAUX_glaux_h

#include <LDL/GLAUX/config.h>
#include <LDL/OpenGL/GL1_2.hpp>

#ifdef __cplusplus
extern "C" {
#endif

#define AUX_RGB             (0)
#define AUX_RGBA            (AUX_RGB)
#define AUX_INDEX           (1)
#define AUX_SINGLE          (0)
#define AUX_DOUBLE          (2)
#define AUX_DIRECT          (0)
#define AUX_INDIRECT        (4)

#define AUX_ACCUM           (8)
#define AUX_ALPHA           (16)
#define AUX_DEPTH           (32)
#define AUX_STENCIL         (64)
#define AUX_AUX             (128)
#define AUX_DEPTH16         (256)
#define AUX_FIXED_332_PAL   (512)

GLAUX_DECLSPEC void   GLAUXCALL auxInitDisplayMode(GLenum mode);
GLAUX_DECLSPEC void   GLAUXCALL auxInitPosition(int x, int y, int w, int h);
GLAUX_DECLSPEC GLenum GLAUXCALL auxInitWindow(const char* title);
GLAUX_DECLSPEC void   GLAUXCALL auxMainLoop(void(*func)());
GLAUX_DECLSPEC void   GLAUXCALL auxReshapeFunc(void(*func)(GLsizei, GLsizei));

GLAUX_DECLSPEC void GLAUXCALL auxSleep(size_t ticks);

#ifdef __cplusplus
}
#endif

#endif
