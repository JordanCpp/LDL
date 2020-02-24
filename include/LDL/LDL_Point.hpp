#ifndef _LDL_Point_hpp_
#define _LDL_Point_hpp_

#include <stdint.h> 

namespace LDL
{

class Point
{
public:
  Point(uint16_t x, uint16_t y);
  void Size(uint16_t x, uint16_t y);
  uint16_t PosX();
  uint16_t PosY();

private:
  uint16_t mX;
  uint16_t mY;
};

Point::Point(uint16_t x, uint16_t y):
mX(x), 
mY(y)
{
}

void Point::Size(uint16_t x, uint16_t y)
{
  mX = x;
  mY = y;
}

uint16_t Point::PosX()
{
  return mX;
}

uint16_t Point::PosY()
{
  return mY;
}

}

#endif