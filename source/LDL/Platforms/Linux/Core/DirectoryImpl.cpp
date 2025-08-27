// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include "DirectoryImpl.hpp"
#include <sys/stat.h>

using namespace LDL;

DirectoryImpl::DirectoryImpl(Result &result) : 
    _result(result)
{
}

const char *DirectoryImpl::AllFiles()
{
    _AllFiles[0] = '.';
    _AllFiles[1] = '/';
    _AllFiles[2] = '\0';

    return _AllFiles;
}

bool DirectoryImpl::Create(const char *path)
{
    return false;
}

bool DirectoryImpl::DirExist(const char *path)
{
    return false;
}

bool DirectoryImpl::FileExist(const char *path)
{
    struct stat st;

    return (stat(path, &st) == 0);
}

bool DirectoryImpl::Delete(const char *path)
{
    return false;
}

bool DirectoryImpl::Open(const char *path)
{
    Close();

    _Directory = opendir(path);

    return _Directory != NULL;
}

void DirectoryImpl::Close()
{
    if (_Directory != NULL)
    {
        closedir(_Directory);
    }
}

bool DirectoryImpl::Next(FileInfo &fileInfo)
{
    dirent *entry = readdir(_Directory);

    if (entry == NULL)
    {
        return false;
    }
    else
    {
        fileInfo.Name(entry->d_name);

        return true;
    }
}

bool DirectoryImpl::Remove(const char *path)
{
    return false;
}