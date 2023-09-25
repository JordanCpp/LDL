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

#if defined(_WIN32)
#define LDL_EXPORT __declspec(dllexport)
#define LDL_IMPORT __declspec(dllimport)
#elif defined(__unix__)
#define LDL_EXPORT __attribute__((visibility("default")))
#define LDL_IMPORT
#else
#define LDL_EXPORT
#define LDL_IMPORT
#endif 

#if defined(LDL_STATIC_LIBRARY)
#define LDL_LIBRARY
#else
#if defined(LDL_SHARED_LIBRARY)
#define LDL_LIBRARY LDL_EXPORT
#else
#define LDL_LIBRARY LDL_IMPORT
#endif
#endif

#if defined(_WIN32)
#define LDL_API_CALL __stdcall *
#elif defined(__unix__)
#define LDL_API_CALL *
#else
#define LDL_API_CALL
#endif  

#define LDL_API_ENTRY LDL_EXPORT extern

#endif
