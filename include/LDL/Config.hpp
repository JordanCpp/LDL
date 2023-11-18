#ifndef LDL_Config_hpp
#define LDL_Config_hpp

#include <LDL/Core/Types.hpp>

#if defined(_WIN32) || defined(WIN32)
  #define LDL_CONFIG_COLOR_BGRA
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

#if defined(_WIN32)
#define LDL_CALL __stdcall
#else
#define LDL_CALL
#endif

#define LDL_API_ENTRY LDL_LIBRARY extern

#endif    
