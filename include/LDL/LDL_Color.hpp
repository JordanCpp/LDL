#ifndef _LDL_Color_hpp_
#define _LDL_Color_hpp_

#include <stdint.h> 

namespace LDL
{

class Color
{
public:
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
  void Red(uint8_t Value);
  void Green(uint8_t Value);
  void Blue(uint8_t Value);
  void Alpha(uint8_t Value);
  uint8_t Red();
  uint8_t Green();
  uint8_t Blue();
  uint8_t Alpha();
//private:
  uint8_t mRed;
  uint8_t mGreen;
  uint8_t mBlue; 
  uint8_t mAlpha;
};

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a):
mRed(r), mGreen(g), mBlue(b), mAlpha(a)
{
}

void Color::Red(uint8_t Value)
{
  mRed = Value;
}

void Color::Green(uint8_t Value)
{
  mGreen = Value;
}

void Color::Blue(uint8_t Value)
{
  mBlue = Value;
}

void Color::Alpha(uint8_t Value)
{
  mAlpha = Value;
}

uint8_t Color::Red()
{
  return mRed;
}

uint8_t Color::Green()
{
  return mGreen;
}

uint8_t Color::Blue()
{
  return mBlue;
}

uint8_t Color::Alpha()
{
  return mAlpha;
}

}

#endif