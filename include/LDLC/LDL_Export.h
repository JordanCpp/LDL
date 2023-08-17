#ifndef LDL_Export_h
#define LDL_Export_h

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
