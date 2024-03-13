#include <LDL/LDL_Image.hpp>

int main()
{
	LDL_ImageLoader imageLoader;

	int width;
	int heigth;
	int bpp;
	unsigned char* pixels;

	if (imageLoader.Load("test.png"))
	{
		width  = imageLoader.Width();
		heigth = imageLoader.Heigth();
		bpp    = imageLoader.Bpp();
		pixels = imageLoader.Pixels();
	}

	return 0;
}