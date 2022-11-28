#ifndef LDL_Platforms_Windows_hpp
#define LDL_Platforms_Windows_hpp

#ifdef NOMINMAX
#include <windows.h>
#else
#define NOMINMAX
#include <windows.h>
#undef NOMINMAX
#endif

#if !defined INVALID_ATOM
#define INVALID_ATOM ((ATOM)0)
#endif

#endif  