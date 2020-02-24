#ifndef _LDL_Ticks_hpp_
#define _LDL_Ticks_hpp_

#include <stdint.h> 
#include <windows.h>

namespace LDL
{

uint32_t Ticks()
{
  return GetTickCount();
}

void Delay(uint32_t Count)
{
  Sleep(Count);
}

}

#endif