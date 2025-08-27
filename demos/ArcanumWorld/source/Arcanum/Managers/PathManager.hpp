// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef Arcanum_Managers_PathManager_hpp
#define Arcanum_Managers_PathManager_hpp

#include <string>

namespace Arcanum
{
	class PathManager
	{
	public:
		PathManager(const std::string& path);
		const std::string& NewShortPath(const std::string& dir, const std::string& file);
		const std::string& NewFullPath(const std::string& dir, const std::string& file);
	private:
		std::string _shortPath;
		std::string _fullPath;
	};
}

#endif    
