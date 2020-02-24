#ifndef _LDL_FrameBuffer_hpp_
#define _LDL_FrameBuffer_hpp_

#include <stdint.h> 

namespace LDL
{

class FrameBuffer
{
public:
  FrameBuffer(uint16_t Width, uint16_t Height, Color Cr = Color(0, 0, 0));
  void SetColor(Color Cr);
  void Clear();
private:
  uint16_t mWidth;
  uint16_t mHeight;
  Color mColor;
  std::vector<Color> mBuffer;
};

FrameBuffer::FrameBuffer(uint16_t Width, uint16_t Height, Color Cr):
mWidth(Width),
mHeight(Height),
mColor(Cr)
{
  Clear();
}

void FrameBuffer::SetColor(Color Cr)
{
  mColor = Cr;
}

void FrameBuffer::Clear()
{
  mBuffer.resize(mWidth * mHeight, mColor);
}

}

#endif