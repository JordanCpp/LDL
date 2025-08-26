// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Arcanum/Managers/PathManager.hpp>

using namespace Arcanum::Managers;

PathManager::PathManager(const std::string& path) :
	_shortPath(path)
{
}

const std::string& PathManager::NewShortPath(const std::string& dir, const std::string& file)
{
	_fullPath.clear();

	_fullPath += dir;
	_fullPath += file;

	return _fullPath;
}

const std::string& PathManager::NewFullPath(const std::string& dir, const std::string& file)
{
	_fullPath.clear();

	_fullPath += _shortPath;
	_fullPath += dir;
	_fullPath += file;

	return _fullPath;
}
