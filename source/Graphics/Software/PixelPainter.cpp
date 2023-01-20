#include <LDL/Graphics/PixelPainter.hpp>
#include <assert.h>

using namespace LDL::Graphics;

PixelPainter::PixelPainter() :
	_Red(0),
	_Green(0),
	_Blue(0),
	_Alpha(0),
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

	_Red = _Color.Red();
	_Green = _Color.Green();
	_Blue = _Color.Blue();
	_Alpha = _Color.Alpha();
}

void PixelPainter::Clear()
{
	size_t size = _Width * _Heigth * _BytesPerPixel;

	size_t i = 0;

	switch(_BytesPerPixel)
	{
  case 4:
	  for (i = 0; i < size; i += 4)
	  {
#if defined(LDL_CONFIG_COLOR_BGRA)
		  _Pixels[i] = _Blue;
		  _Pixels[i + 2] = _Red;
#else
		  _Pixels[i] = _Red;
		  _Pixels[i + 2] = _Blue;
#endif
		  _Pixels[i + 1] = _Green;
		  _Pixels[i + 3] = _Alpha;
	  }
	  break;
  case 3:
	  for (i = 0; i < size; i += 3)
	  {
#if defined(LDL_CONFIG_COLOR_BGRA)
		  _Pixels[i] = _Blue;
		  _Pixels[i + 2] = _Red;
#else
		  _Pixels[i] = _Red;
		  _Pixels[i + 2] = _Blue;
#endif
		  _Pixels[i + 1] = _Green;
	  }
	  break;
  case 2:
	  for (i = 0; i < size; i += 2)
	  {
		  _Pixels[i] = _Red;
		  _Pixels[i + 1] = _Green;
	  }
	  break;
  default:
	  for (i = 0; i < size; i++)
	  {
		  _Pixels[i] = _Red;
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
	size_t i = (_Width * pos._PosY + pos._PosX) * _BytesPerPixel;

	assert(i < _Width * _Heigth * _BytesPerPixel);

	switch (_BytesPerPixel)
	{
	case 4:
#if defined(LDL_CONFIG_COLOR_BGRA)
		_Pixels[i] = _Blue;
		_Pixels[i + 2] = _Red;
#else
		_Pixels[i] = _Red;
		_Pixels[i + 2] = _Blue;
#endif
			_Pixels[i + 1] = _Green;
			_Pixels[i + 3] = _Alpha;
		break;
	case 3:
#if defined(LDL_CONFIG_COLOR_BGRA)
		_Pixels[i] = _Blue;
		_Pixels[i + 2] = _Red;
#else
		_Pixels[i] = _Red;
		_Pixels[i + 2] = _Blue;
#endif
		_Pixels[i + 1] = _Green;
		break;
	case 2:
			_Pixels[i] = _Red;
			_Pixels[i + 1] = _Green;
		break;
	default:
			_Pixels[i] = _Red;
	}
}

const LDL::Graphics::Color& PixelPainter::GetPixel(const Point2u& pos)
{
	size_t i = (_Width * pos._PosY + pos._PosX) * _BytesPerPixel;

	assert(i < _Width * _Heigth * _BytesPerPixel);

	switch (_BytesPerPixel)
	{
	case 4:
#if defined(LDL_CONFIG_COLOR_BGRA)
		_ColorGetPixel = LDL::Graphics::Color(_Pixels[i + 2], _Pixels[i + 1], _Pixels[i], _Pixels[i + 3]);
#else
		_ColorGetPixel = LDL::Graphics::Color(_Pixels[i], _Pixels[i + 1], _Pixels[i + 2], _Pixels[i + 3]);
#endif
		break;
	case 3:
#if defined(LDL_CONFIG_COLOR_BGRA)
		_ColorGetPixel = LDL::Graphics::Color(_Pixels[i + 2], _Pixels[i + 1], _Pixels[i], 0);
#else
		_ColorGetPixel = LDL::Graphics::Color(_Pixels[i], _Pixels[i + 1], _Pixels[i + 2], 0);
#endif
		break;
	case 2:
		_ColorGetPixel = LDL::Graphics::Color(_Pixels[i], _Pixels[i + 1], 0, 0);
		break;
	default:
		_ColorGetPixel = LDL::Graphics::Color(_Pixels[i], 0, 0, 0);
	}

	return _ColorGetPixel;
}

void PixelPainter::Fill(const Point2u& pos, const Point2u& size)
{
	assert(size.PosX() > 0);
	assert(size.PosY() > 0);

	size_t x = pos.PosX();
	size_t y = pos.PosY();

	for (size_t i = 0; i < size._PosX; i++)
	{
		for (size_t j = 0; j < size._PosY; j++)
		{
			Pixel(Point2u(x + i, y + j));
		}
	}
}

void PixelPainter::Line(const Point2u& pos1, const Point2u& pos2)
{
	int x1 = (int)pos1.PosX();
	int y1 = (int)pos1.PosY();

	int x2 = (int)pos2.PosX();
	int y2 = (int)pos2.PosY();

	int deltaX;
	int deltaY;
	int signX;
	int signY;
	int error;
	int error2;

	deltaX = abs(x2 - x1);
	deltaY = abs(y2 - y1);
	signX = x1 < x2 ? 1 : -1;
	signY = y1 < y2 ? 1 : -1;

	error = deltaX - deltaY;

	Pixel(Point2u(x2, y2));

	while (x1 != x2 || y1 != y2)
	{
		Pixel(Point2u(x1, y1));

		error2 = error * 2;

		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}

		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}
}