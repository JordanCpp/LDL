#include <Arcanum/Graphics/Sprite.hpp>

using namespace Arcanum::Graphics;

Sprite::~Sprite()
{
	for (size_t i = 0; i < _Images.size(); i++)
		delete _Images[i];
}
void Sprite::Append(Image* image)
{
	_Images.push_back(image);
}

Image* Sprite::GetImage(size_t index)
{
	return _Images[index];
}

Image* Sprite::Single()
{
	return GetImage(0);
}