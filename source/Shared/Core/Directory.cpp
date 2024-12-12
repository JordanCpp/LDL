#include <LDL/Core/Directory.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Core/DirectoryImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Core/DirectoryImpl.hpp"
#endif

using namespace LDL::Core;

Directory::Directory() :
    _impl(new LDL::Core::DirectoryImpl())
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

bool Directory::Create(const std::string& path)
{
    return _impl->Create(path);
}

bool Directory::DirExist(const std::string& path)
{
    return _impl->DirExist(path);
}

bool Directory::FileExist(const std::string& path)
{
    return _impl->FileExist(path);
}

bool Directory::Delete(const std::string& path)
{
    return _impl->Delete(path);
}

bool Directory::Open(const std::string& path)
{
    return _impl->Open(path);
}

void Directory::Close()
{
    _impl->Close();
}

bool Directory::Next(LDL::Core::FileInfo& fileInfo)
{
    return _impl->Next(fileInfo);
}

bool Directory::Remove(const std::string& path)
{
    return _impl->Remove(path);
}
