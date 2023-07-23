#include <LDL/Core/Directory.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Core/DirectoryImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Core/DirectoryImpl.hpp"
#endif

using namespace LDL::Core;

Directory::Directory() :
    _DirectoryImpl(new LDL::Core::DirectoryImpl())
{
}

Directory::~Directory()
{
    delete _DirectoryImpl;
}

bool Directory::Create(const std::string& path)
{
    return _DirectoryImpl->Create(path);
}

bool Directory::Exist(const std::string& path)
{
    return _DirectoryImpl->Exist(path);
}

bool Directory::Delete(const std::string& path)
{
    return _DirectoryImpl->Delete(path);
}

bool Directory::Open(const std::string& path)
{
    return _DirectoryImpl->Open(path);
}

void Directory::Close()
{
    _DirectoryImpl->Close();
}

bool Directory::Next(LDL::Core::FileInfo& fileInfo)
{
    return _DirectoryImpl->Next(fileInfo);
}

bool Directory::Remove(const std::string& path)
{
    return _DirectoryImpl->Remove(path);
}
