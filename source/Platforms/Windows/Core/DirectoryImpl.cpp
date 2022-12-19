#include "DirectoryImpl.hpp"

using namespace LDL::Core;

bool DirectoryImpl::Create(const std::string& path)
{
    return CreateDirectory(path.c_str(), NULL);
}

bool DirectoryImpl::Exist(const std::string& path)
{
    return GetFileAttributes(path.c_str()) != DWORD(-1);
}

bool DirectoryImpl::Delete(const std::string& path)
{
    return RemoveDirectory(path.c_str());
}

bool DirectoryImpl::Open(const std::string& path)
{
    _File = FindFirstFile(path.c_str(), &_Data);

    return _File != INVALID_HANDLE_VALUE;
}

void DirectoryImpl::Close()
{
    FindClose(_File);
}

bool DirectoryImpl::Next(FileInfo& fileInfo)
{
    BOOL result = FindNextFile(_File, &_Data);

    if (result)
        fileInfo.Name(_Data.cFileName);

    return result;
}

bool DirectoryImpl::Remove(const std::string& path)
{
    return DeleteFile(path.c_str());
}