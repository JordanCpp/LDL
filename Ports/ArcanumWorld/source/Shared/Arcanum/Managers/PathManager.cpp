#include <Arcanum/Managers/PathManager.hpp>

using namespace Arcanum::Managers;

PathManager::PathManager(const std::string& path) :
	_ShortPath(path)
{
}

const std::string& PathManager::NewShortPath(const std::string& dir, const std::string& file)
{
	_FullPath.clear();

	_FullPath += dir;
	_FullPath += file;

	return _FullPath;
}

const std::string& PathManager::NewFullPath(const std::string& dir, const std::string& file)
{
	_FullPath.clear();

	_FullPath += _ShortPath;
	_FullPath += dir;
	_FullPath += file;

	return _FullPath;
}
