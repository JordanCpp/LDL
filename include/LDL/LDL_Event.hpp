#ifndef _LDL_Event_hpp_
#define _LDL_Event_hpp_

#include <stdint.h> 

namespace LDL
{

struct EventQuit
{
  size_t Type;
};

struct EventMouseMove
{
  size_t Type;
  uint16_t PosX;
  uint16_t PosY;
};

struct EventMouseButton
{
  size_t Type;
  size_t Button;
  size_t State;
  uint16_t PosX;
  uint16_t PosY;
};

struct EventResize
{
  size_t Type;
  uint16_t Width;
  uint16_t Height;
};

union Event
{
enum
{
  IsQuit,
  IsMouseMove,
  IsMouseButton,
  IsResize,
  ButtonLeft,
  ButtonRight,
  ButtonDown,
  ButtonUp
};

  size_t Type;
  EventQuit        Quit;
  EventMouseMove   MouseMove;
  EventMouseButton MouseButton;
  EventResize      Resize;
};

}

#endif