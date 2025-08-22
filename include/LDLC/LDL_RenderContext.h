// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_RenderContext_h
#define LDL_RenderContext_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_RenderContext LDL_RenderContext;

LDL_LIBRARY LDL_RenderContext* LDL_RenderContextNew();
LDL_LIBRARY void LDL_RenderContextFree(LDL_RenderContext* renderContext);
LDL_LIBRARY void LDL_RenderContextGetContext(LDL_RenderContext* renderContext);

#ifdef __cplusplus
}
#endif

#endif
