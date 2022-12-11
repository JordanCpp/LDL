#include "DirectoryImpl.hpp"

bool LDL::Core::DirectoryImpl::Create(const std::string& path)
{
    return CreateDirectory(path.c_str(), NULL);
}

bool LDL::Core::DirectoryImpl::Exist(const std::string& path)
{
    DWORD attr = GetFileAttributes(path.c_str());

    return (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool LDL::Core::DirectoryImpl::Delete(const std::string& path)
{
    return RemoveDirectory(path.c_str());
}

bool LDL::Core::DirectoryImpl::Open(const std::string& path)
{
    _File = FindFirstFile(path.c_str(), &_Data);

    return _File != INVALID_HANDLE_VALUE;
}

void LDL::Core::DirectoryImpl::Close()
{
    FindClose(_File);
}

bool LDL::Core::DirectoryImpl::Next(LDL::Core::FileInfo& fileInfo)
{
    BOOL result = FindNextFile(_File, &_Data);

    if (result)
        fileInfo.Name(_Data.cFileName);

    return result;
}