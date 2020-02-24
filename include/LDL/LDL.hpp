#ifndef _LDL_hpp_
#define _LDL_hpp_

#include "LDL_Point.hpp"
#include "LDL_Color.hpp"
#include "LDL_Rect.hpp"
#include "LDL_Event.hpp"
#include "LDL_FrameBuffer.hpp"

#ifdef LDL_PlatformWindows
  #include "Windows\LDL_Ticks.hpp"
  #include "Windows\LDL_Canvas.hpp"
  #include "Windows\LDL_Dir.hpp"
#else
  #error "Platform indefined!"
#endif

#endif