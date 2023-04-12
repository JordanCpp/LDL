#ifndef LDL_Export_h
#define LDL_Export_h

#if defined(LDL_STATIC_LIBRARY)
#define LDL_EXPORT
#else
#if defined(LDL_SHARED_LIBRARY)
#define LDL_EXPORT __declspec(dllexport)
#else
#define LDL_EXPORT __declspec(dllimport)
#endif
#endif

#endif