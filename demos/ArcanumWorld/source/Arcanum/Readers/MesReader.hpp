// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Readers_MesReader_hpp
#define Arcanum_Readers_MesReader_hpp

#include <string>
#include <fstream>

namespace Arcanum
{
	class MesReader
	{
	public:
		void Reset(const std::string& path);
		void Close();
		char NextChar();
		bool Next();
		const std::string& Result();
		bool Eof();
	private:
		std::fstream _file;
		std::string  _result;
		size_t       _tabs;
		size_t       _line;
	};
}

#endif    
