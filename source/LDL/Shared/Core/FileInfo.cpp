#include <LDL/Core/FileInfo.hpp>

using namespace LDL::Core;

const std::string& FileInfo::Name()
{
	return _name;
}

void FileInfo::Name(const std::string& source)
{
	_name = source;
}
