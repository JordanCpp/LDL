// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/New.hpp>
#include <LDL/Core/Directory.hpp>

#if defined(_WIN32)
    #include <LDL/Platforms/Windows/Core/DirectoryImpl.hpp>
#elif defined(__unix__)
    #include <LDL/Platforms/Linux/Core/DirectoryImpl.hpp>
#endif

using namespace LDL;

Directory::Directory(Result& result) :
    _result(result),
    _impl(new(_memory) DirectoryImpl(result))
{
}

Directory::~Directory()
{
    delete _impl;
}

const char* Directory::AllFiles()
{
    return _impl->AllFiles();
}

bool Directory::Create(const char* path)
{
    return _impl->Create(path);
}

bool Directory::DirExist(const char* path)
{
    return _impl->DirExist(path);
}

bool Directory::FileExist(const char* path)
{
    return _impl->FileExist(path);
}

bool Directory::Delete(const char* path)
{
    return _impl->Delete(path);
}

bool Directory::Open(const char* path)
{
    return _impl->Open(path);
}

void Directory::Close()
{
    _impl->Close();
}

bool Directory::Next(FileInfo& fileInfo)
{
    return _impl->Next(fileInfo);
}

bool Directory::Remove(const char* path)
{
    return _impl->Remove(path);
}
