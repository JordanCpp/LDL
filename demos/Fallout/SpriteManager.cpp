/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#include "SpriteManager.hpp"

using namespace LDL;
using namespace Fallout;

SpriteManager::SpriteManager(SpriteLoader& spriteLoader) :
	_spriteLoader(spriteLoader)
{
}

SpriteManager::~SpriteManager()
{
	for (std::map<std::string, Sprite*>::iterator i = _sprites.begin(); i != _sprites.end(); i++)
	{
		delete i->second;
	}
}

Sprite* SpriteManager::GetSprite(const std::string& path)
{
	std::map<std::string, Sprite*>::iterator i = _sprites.find(path);

	if (i == _sprites.end())
	{
		Sprite* sprite = _spriteLoader.LoadSprite(path);
		_sprites.insert(std::make_pair(path, sprite));

		return sprite;
	}

	return i->second;
}
