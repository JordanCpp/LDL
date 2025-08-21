#include <Arcanum/Graphics/Sprite.hpp>

using namespace Arcanum::Graphics;

Sprite::~Sprite()
{
	for (size_t i = 0; i < _images.size(); i++)
	{
		delete _images[i];
	}
}

void Sprite::Append(Image* image)
{
	_images.push_back(image);
}

Image* Sprite::GetImage(size_t index)
{
	return _images[index];
}

Image* Sprite::Single()
{
	return GetImage(0);
}