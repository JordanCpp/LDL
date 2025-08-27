// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Writters_XmlWriter_hpp
#define Arcanum_Writters_XmlWriter_hpp

#include <fstream>
#include <string>
#include <LDL/Core/Convert.hpp>

namespace Arcanum
{
	class XmlWriter
	{
	public:
		~XmlWriter();
		bool Reset(const std::string& path);
		void Close();
		void TagBegin(const std::string& name);
		void TagEnd(const std::string& name);
		void Node(const std::string& name, const std::string& data);
		void Node(const std::string& name, intmax_t data);
	private:
		std::ofstream _file;
		LDL::Convert  _convert;
	};
}

#endif
