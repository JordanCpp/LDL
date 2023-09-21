#ifndef LDL_Low_Config_hpp
#define LDL_Low_Config_hpp

#include <stdlib.h>

#if (__BORLANDC__)
#include <alloc.h>
#define LDL_FAR far
#define LDL_MALLOC farmalloc
#define LDL_FREE farfree
#elif (_MSC_VER <= 1600)
#define LDL_FAR
#define LDL_MALLOC malloc
#define LDL_FREE free
#else
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#define LDL_FAR
#define LDL_MALLOC malloc
#define LDL_FREE free
#endif

#endif
