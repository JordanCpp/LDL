#ifndef _LDL_Rect_hpp_
#define _LDL_Rect_hpp_

#include <stdint.h> 

namespace LDL
{

class Rect
{
public:
  uint16_t PosX();
  uint16_t PosY();
  uint16_t Width();
  uint16_t Height();
  void Size(uint16_t w, uint16_t h);
  Rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
  bool In(uint16_t x, uint16_t y);

private:
  uint16_t mX;
  uint16_t mY;
  uint16_t mW; 
  uint16_t mH;
};

uint16_t Rect::PosX()
{
  return mX;
}

uint16_t Rect::PosY()
{
  return mY;
}


uint16_t Rect::Width()
{
  return mW;
}

uint16_t Rect::Height()
{
  return mH;
}

void Rect::Size(uint16_t w, uint16_t h)
{
  mW = w;
  mH = h;
}

Rect::Rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h):
mX(x), mY(y), mW(w), mH(h)
{
}

bool Rect::In(uint16_t xv, uint16_t yv)
{
  return ((xv >= mX) && (yv >= mY) && (xv <= mX + mW) && (yv <= mY + mH));
}

}

#endif