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

#include "ImageLoader.hpp"

using namespace LDL;
using namespace Fallout;

ImageLoader::ImageLoader(Result& result, Context& context) :
	_result(result),
	_context(context),
	_loader(_result)
{
}

Texture* ImageLoader::Load(const std::string& path)
{
	_loader.Load(path);

	Surface surface(_result, _loader.GetPixelFormat(), _loader.GetSize(), _loader.GetPixels());
	surface.SetColorKey(Color(11, 0, 11));

	return new Texture(_result, _context, &surface);
}

Sprite* ImageLoader::LoadSprite(const std::string& path)
{
	_loader.Load(path);

	Surface surface(_result, _loader.GetPixelFormat(), _loader.GetSize(), _loader.GetPixels());
	surface.SetColorKey(Color(11, 0, 11));

	Sprite* sprite = new Sprite();
	sprite->Append(0, new Texture(_result, _context, &surface));

	return sprite;
}
