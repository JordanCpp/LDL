#ifndef LDL_Types_hpp
#define LDL_Types_hpp

#include <stddef.h>

#if defined(_WIN64) || defined(_WIN32)
  #define LDL_COLOR_BGRA
#else
  #define LDL_COLOR_RGBA
#endif 

#if (_MSC_VER <= 1600 && !__MINGW32__) || (__BORLANDC__)
typedef signed char    int8_t;
typedef unsigned char  uint8_t;

typedef signed short   int16_t;
typedef unsigned short uint16_t;

typedef signed long    int32_t;
typedef unsigned long  uint32_t;

typedef int32_t        intmax_t;

#define bool  int 
#define true  1 
#define false 0
#else
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#endif

#endif
