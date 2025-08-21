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
