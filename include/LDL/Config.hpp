#ifndef LDL_Config_hpp
#define LDL_Config_hpp

#include <LDL/Core/Types.hpp>

#if defined(_WIN32) || defined(WIN32)
  #define LDL_CONFIG_COLOR_BGRA
#endif

#if defined(LDL_CONFIG_STATIC_LIBRARY)
  #define LDL_EXPORT
#else
  #if defined(LDL_CONFIG_SHARED_LIBRARY)
    #define LDL_EXPORT __declspec(dllexport)
  #else
    #define LDL_EXPORT __declspec(dllimport)
  #endif
#endif

#endif    