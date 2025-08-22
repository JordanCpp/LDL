// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_OpenGLLoader_h
#define LDL_OpenGLLoader_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_OpenGLLoader LDL_OpenGLLoader;

LDL_LIBRARY LDL_OpenGLLoader* LDL_OpenGLLoaderNew(size_t major, size_t minor);
LDL_LIBRARY void LDL_OpenGLLoaderFree(LDL_OpenGLLoader* openGLLoader);

#ifdef __cplusplus
}
#endif

#endif
