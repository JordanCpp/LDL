#include <LDL/Core/FileInfo.hpp>

using namespace LDL::Core;

const std::string& FileInfo::Name()
{
	return _Name;
}

void FileInfo::Name(const std::string& source)
{
	_Name = source;
}