// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Windows/Core/DirectoryImpl.hpp>

using namespace LDL::Core;

const char* DirectoryImpl::AllFiles()
{
    _allFiles[0] = '*';
    _allFiles[1] = '.';
    _allFiles[2] = '*';
    _allFiles[3] = '\0';

    return _allFiles;
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
    _file = FindFirstFile(path.c_str(), &_data);

    return _file != INVALID_HANDLE_VALUE;
}

void DirectoryImpl::Close()
{
    FindClose(_file);
}

bool DirectoryImpl::Next(FileInfo& fileInfo)
{
    BOOL result = FindNextFile(_file, &_data);

    if (result)
        fileInfo.Name(_data.cFileName);

    return result;
}

bool DirectoryImpl::Remove(const std::string& path)
{
    return DeleteFile(path.c_str());
}
