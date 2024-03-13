# Greetings
LDL extension library. (https://github.com/JordanCpp/LDL)
The library has no dependencies. Just use it.

# Functional
Loading image formats: bmp, png, jpg, jpeg, gif.

# License.
Boost Software License - Version 1.0 - August 17th, 2003

# Example
```c++
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
```