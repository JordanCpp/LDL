#ifndef LDL_Config_hpp
#define LDL_Config_hpp

#include <LDL/Core/Types.hpp>

#if defined(_WIN32) || defined(WIN32)
  #define LDL_CONFIG_COLOR_BGRA
#endif

#if defined(LDL_STATIC_LIBRARY)
  #define LDL_EXPORT
#else
    #if defined(_WIN32)
      #define LDL_EXPORT __declspec(dllimport)
    #elif defined(__unix__)
      #define LDL_EXPORT __attribute__((visibility("default")))
    #endif
#endif

#endif    
