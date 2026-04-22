
#ifndef LDL_Vec2i_H
#define LDL_Vec2i_H

#include <LDL/Config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_Vec2i
{
	int x;
	int y;

} LDL_Vec2i;

LDL_LIBRARY LDL_Vec2i LDL_GetVec2i(int x, int y);

#ifdef __cplusplus
}
#endif 

#endif
