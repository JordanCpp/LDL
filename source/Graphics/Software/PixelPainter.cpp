#include <LDL/Graphics/PixelPainter.hpp>
#include <assert.h>

using namespace LDL::Graphics;

PixelPainter::PixelPainter() :
	_Target(NULL),
	_Width(0),
	_Heigth(0),
	_BytesPerPixel(0),
	_Pixels(NULL)
{
}

PixelPainter::~PixelPainter()
{
}

Surface* PixelPainter::Target()
{
	return _Target;
}

const Point2u& PixelPainter::Size()
{
	_Size = Point2u(_Width, _Heigth);

	return _Size;
}

uint8_t PixelPainter::BytesPerPixel()
{
	return _BytesPerPixel;
}

uint8_t* PixelPainter::Pixels()
{
	return _Pixels;
}

const LDL::Graphics::Color& LDL::Graphics::PixelPainter::Color()
{
	return _Color;
}

void LDL::Graphics::PixelPainter::Color(const LDL::Graphics::Color& color)
{
	_Color = color;
}

void PixelPainter::Clear()
{
	size_t size = _Width * _Heigth * _BytesPerPixel;

	switch(_BytesPerPixel)
	{
  case 4:
	  for (size_t i = 0; i < size; i += 4)
	  {
		  _Pixels[i] = _Color.Red();
		  _Pixels[i + 1] = _Color.Green();
		  _Pixels[i + 2] = _Color.Blue();
		  _Pixels[i + 3] = _Color.Alpha();
	  }
	  break;
  case 3:
	  for (size_t i = 0; i < size; i += 3)
	  {
		  _Pixels[i] = _Color.Red();
		  _Pixels[i + 1] = _Color.Green();
		  _Pixels[i + 2] = _Color.Blue();
	  }
	  break;
  case 2:
	  for (size_t i = 0; i < size; i += 2)
	  {
		  _Pixels[i] = _Color.Red();
		  _Pixels[i + 1] = _Color.Green();
	  }
	  break;
  default:
	  for (size_t i = 0; i < size; i++)
	  {
		  _Pixels[i] = _Color.Red();
	  }
	}
}

void PixelPainter::Bind(Surface* source)
{
	assert(source != NULL);

	_Target = source;

	_Width = _Target->Size().PosX();
	_Heigth = _Target->Size().PosY();
	_BytesPerPixel = _Target->BytesPerPixel();
	_Pixels = _Target->Pixels();
}

void PixelPainter::Pixel(const Point2u& pos)
{
	size_t i = (_Width * pos._PosY) + pos._PosX;

	assert(i < _Width * _Heigth * _BytesPerPixel);

	switch (_BytesPerPixel)
	{
	case 4:
			_Pixels[i] = _Color.Red();
			_Pixels[i + 1] = _Color.Green();
			_Pixels[i + 2] = _Color.Blue();
			_Pixels[i + 3] = _Color.Alpha();
		break;
	case 3:
			_Pixels[i] = _Color.Red();
			_Pixels[i + 1] = _Color.Green();
			_Pixels[i + 2] = _Color.Blue();
		break;
	case 2:
			_Pixels[i] = _Color.Red();
			_Pixels[i + 1] = _Color.Green();
		break;
	default:
			_Pixels[i] = _Color.Red();
	}
}

const LDL::Graphics::Color& PixelPainter::GetPixel(const Point2u& pos)
{
	size_t i = (_Width * pos._PosY) + pos._PosX;

	assert(i < _Width* _Heigth* _BytesPerPixel);

	switch (_BytesPerPixel)
	{
	case 4:
		_ColorGetPixel = LDL::Graphics::Color(_Color.Red(), _Color.Green(), _Color.Blue(), _Color.Alpha());
		break;
	case 3:
		_ColorGetPixel = LDL::Graphics::Color(_Color.Red(), _Color.Green(), _Color.Blue(), 0);
		break;
	case 2:
		_ColorGetPixel = LDL::Graphics::Color(_Color.Red(), _Color.Green(), 0, 0);
		break;
	default:
		_ColorGetPixel = LDL::Graphics::Color(_Color.Red(), 0, 0, 0);
	}

	return _ColorGetPixel;
}