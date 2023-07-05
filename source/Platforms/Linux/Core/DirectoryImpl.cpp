#include "DirectoryImpl.hpp"

using namespace LDL::Core;

bool DirectoryImpl::Create(const std::string& path)
{
    return false;
}

bool DirectoryImpl::Exist(const std::string& path)
{
    return false;
}

bool DirectoryImpl::Delete(const std::string& path)
{
    return false;
}

bool DirectoryImpl::Open(const std::string& path)
{
    Close();
    
    _Directory = opendir(path.c_str());

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

bool DirectoryImpl::Remove(const std::string& path)
{
    return false;
}