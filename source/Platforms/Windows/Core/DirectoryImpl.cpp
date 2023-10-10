#include "DirectoryImpl.hpp"

using namespace LDL::Core;

const char* DirectoryImpl::AllFiles()
{
    _AllFiles[0] = '*';
    _AllFiles[1] = '.';
    _AllFiles[2] = '*';
    _AllFiles[3] = '\0';

    return _AllFiles;
}

bool DirectoryImpl::Create(const std::string& path)
{
    return CreateDirectory(path.c_str(), NULL);
}

bool DirectoryImpl::DirExist(const std::string& path)
{
    DWORD attr = GetFileAttributes(path.c_str());

    return (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool DirectoryImpl::FileExist(const std::string& path)
{
    DWORD attr = GetFileAttributes(path.c_str());

    return (attr != INVALID_FILE_ATTRIBUTES && !(attr & FILE_ATTRIBUTE_DIRECTORY));
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
