// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Platforms/Win9X/WinError.hpp>
#include <LDL/Platforms/Win9X/Core/DirectoryImpl.hpp>

using namespace LDL;

DirectoryImpl::DirectoryImpl(Result& result) :
    _result(result),
    _file(INVALID_HANDLE_VALUE)
{
    LDL_memset(&_allFiles, 0, sizeof(_allFiles));
    LDL_memset(&_data, 0, sizeof(_data));
}

const char* DirectoryImpl::AllFiles()
{
    _allFiles[0] = '*';
    _allFiles[1] = '.';
    _allFiles[2] = '*';
    _allFiles[3] = '\0';

    return _allFiles;
}

bool DirectoryImpl::Create(const char* path)
{
    bool create = CreateDirectory(path, NULL);

    if (!create)
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return false;
    }

    return true;
}

bool DirectoryImpl::DirExist(const char* path)
{
    DWORD attr = GetFileAttributesA(path);

    if ((attr == INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY)))
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return false;
    }

    return true;
}

bool DirectoryImpl::FileExist(const char* path)
{
    DWORD attr = GetFileAttributesA(path);

    if ((attr == INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY)))
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return false;
    }

    return true;
}

bool DirectoryImpl::Delete(const char* path)
{
    bool remove = RemoveDirectoryA(path);

    if (!remove)
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return false;
    }

    return true;
}

bool DirectoryImpl::Open(const char* path)
{
    _file = FindFirstFileA(path, &_data);

    if (_file == INVALID_HANDLE_VALUE)
    {
        WindowError windowError;
        _result.Message(windowError.GetErrorMessage());
        return false;
    }

    return true;
}

void DirectoryImpl::Close()
{
    if (_file != INVALID_HANDLE_VALUE)
    {
        FindClose(_file);
    }
}

bool DirectoryImpl::Next(FileInfo& fileInfo)
{
    BOOL result = FindNextFileA(_file, &_data);

    if (result)
    {
        fileInfo.Name(_data.cFileName);
    }

    return result;
}

bool DirectoryImpl::Remove(const char* path)
{
    return DeleteFileA(path);
}
