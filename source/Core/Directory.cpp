#include <LDL/Core/Directory.hpp>
#include "../Platforms/Windows/Core/DirectoryImpl.hpp"

LDL::Core::Directory::Directory() :
    _DirectoryImpl(new LDL::Core::DirectoryImpl())
{
}

LDL::Core::Directory::~Directory()
{
    delete _DirectoryImpl;
}

bool LDL::Core::Directory::Create(const std::string& path)
{
    return _DirectoryImpl->Create(path);
}

bool LDL::Core::Directory::Exist(const std::string& path)
{
    return _DirectoryImpl->Exist(path);
}

bool LDL::Core::Directory::Delete(const std::string& path)
{
    return _DirectoryImpl->Delete(path);
}

bool LDL::Core::Directory::Open(const std::string& path)
{
    return _DirectoryImpl->Open(path);
}

void LDL::Core::Directory::Close()
{
    _DirectoryImpl->Close();
}

bool LDL::Core::Directory::Next(LDL::Core::FileInfo& fileInfo)
{
    return _DirectoryImpl->Next(fileInfo);
}