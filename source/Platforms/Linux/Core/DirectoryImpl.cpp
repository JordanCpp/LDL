#include "DirectoryImpl.hpp"
#include <sys/stat.h>

using namespace LDL::Core;

const char* DirectoryImpl::AllFiles()
{
    _AllFiles[0] = '.';
    _AllFiles[1] = '/';
    _AllFiles[2] = '\0';

    return _AllFiles;
}

bool DirectoryImpl::Create(const std::string& path)
{
    return false;
}

bool DirectoryImpl::DirExist(const std::string& path)
{
    return false;
}

bool DirectoryImpl::FileExist(const std::string& path)
{
    struct stat st;   

    return (stat (path.c_str(), &st) == 0);
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