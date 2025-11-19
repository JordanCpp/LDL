// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Game_Settings_hpp
#define Arcanum_Game_Settings_hpp

#include <string>
#include <LDL/Vec2u.hpp>

namespace Arcanum
{
	class Settings
	{
	public:
		Settings();
		const std::string& Path();
		void Path(const std::string& path);
		const std::string& Title();
		void Title(const std::string& title);
		const LDL_Vec2u& Size();
		void Size(const LDL_Vec2u& size);
		size_t Fps();
		void Fps(size_t fps);
		size_t Render();
		void Render(size_t render);
		const std::string& DatFiles();
		void DatFiles(const std::string& value);
		const std::string& DataFiles();
		void DataFiles(const std::string& value);
	private:
		size_t       _render;
		size_t       _fps;
		LDL_Vec2u   _size;
		std::string  _path;
		std::string  _title;
		std::string  _datFiles;
		std::string  _dataFiles;
	};
}

#endif
