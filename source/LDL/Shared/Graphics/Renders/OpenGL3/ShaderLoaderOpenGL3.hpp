// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_ShaderLoader_hpp
#define LDL_Graphics_OpenGL3_ShaderLoader_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	class ShaderLoader
	{
	public:
		ShaderLoader();
		~ShaderLoader();
		bool Load(const char* path);
		const char* Result();
	private:
	};
}

#endif    
