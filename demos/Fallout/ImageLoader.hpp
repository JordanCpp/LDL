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

#ifndef Fallout_ImageLoader_hpp
#define Fallout_ImageLoader_hpp

#include "Config.hpp"
#include "Sprite.hpp"
#include <LDL/C++98/LDL.hpp>

namespace Fallout
{
	class ImageLoader
	{
	public:
		ImageLoader(LDL::Result& result, LDL::Context& context);
		LDL::Texture* Load(const std::string& path);
		Sprite* LoadSprite(const std::string& path);
	private:
		LDL::Result&   _result;
		LDL::Context&  _context;
		LDL::BmpLoader _loader;
	};
}

#endif
