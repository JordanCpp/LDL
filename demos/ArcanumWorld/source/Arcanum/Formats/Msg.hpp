// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Formats_Msg_hpp
#define Arcanum_Formats_Msg_hpp

#include <string>

namespace Arcanum
{
	class Msg
	{
	public:
		size_t Number();
		void Number(size_t value);
		const std::string& Content();
		void Content(const std::string& value);
	private:
		size_t      _number;
		std::string _content;
	};
}

#endif
