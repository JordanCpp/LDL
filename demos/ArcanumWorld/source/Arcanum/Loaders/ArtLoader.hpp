// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Loaders_ArtLoader_hpp
#define Arcanum_Loaders_ArtLoader_hpp

#include <LDL/Vec2.hpp>
#include <Arcanum/Formats/Art.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>

namespace Arcanum
{
	class ArtLoader
	{
	public:
		void Load(MemoryReader& memoryReader);
		const LDL_Vec2u& Size();
		const LDL_Vec2u& Offset();
		const LDL_Vec2u& Delta();
		uint8_t* Pixels();
		size_t Frames();
		void Frame(size_t index);
	private:
		ArtFile              _file;
		LDL_Vec2u            _size;
		LDL_Vec2u            _offset;
		LDL_Vec2u            _delta;
		std::vector<uint8_t> _pixels;
	};
}

#endif    
