#include <LDL/Core/FileInfo.hpp>

const std::string& LDL::Core::FileInfo::Name()
{
	return _Name;
}

void LDL::Core::FileInfo::Name(const std::string& source)
{
	_Name = source;
}