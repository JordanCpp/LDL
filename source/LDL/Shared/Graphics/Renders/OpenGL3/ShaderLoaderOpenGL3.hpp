// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Graphics_OpenGL3_ShaderLoader_hpp
#define LDL_Graphics_OpenGL3_ShaderLoader_hpp

#include <fstream>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class ShaderLoader
		{
		public:
			ShaderLoader();
			~ShaderLoader();
			bool Load(const std::string& path);
			const std::string& Result();
		private:
			std::fstream _file;
			std::string  _result;
			std::string  _line;
		};
	}
}

#endif    
