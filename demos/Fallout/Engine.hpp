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

#ifndef Fallout_Engine_hpp
#define Fallout_Engine_hpp

#include "Camera.hpp"
#include "Config.hpp"
#include "Location.hpp"
#include "SpriteManager.hpp"
#include <LDL/C++98/LDL.hpp>

namespace Fallout
{
	class Engine
	{
	public:
		Engine(Config& config);
		~Engine();
		void Input(LDL::Event& event);
		void Run();
		LDL::Result& GetResult();
	private:
		Camera        _camera;
		LDL::Result   _result;
		LDL::Context  _context;
		LDL::Window   _window;
		LDL::Render2D _render;
		SpriteLoader  _imageLoader;
		SpriteManager _spriteManager;
		Location  _location;
		
	};
}

#endif
