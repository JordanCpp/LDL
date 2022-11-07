#include <LDL/Platforms/Windows/Core/Directory.hpp>

bool LDL::Core::Windows::Directory::Create(const std::string& path)
{
    return CreateDirectory(path.c_str(), NULL);
}

bool LDL::Core::Windows::Directory::Exist(const std::string& path)
{
    DWORD attr = GetFileAttributes(path.c_str());

    return (attr != INVALID_FILE_ATTRIBUTES && (attr & FILE_ATTRIBUTE_DIRECTORY));
}

bool LDL::Core::Windows::Directory::Delete(const std::string& path)
{
    return RemoveDirectory(path.c_str());
}

bool LDL::Core::Windows::Directory::Open(const std::string& path)
{
    _File = FindFirstFile(path.c_str(), &_Data);

    return _File != INVALID_HANDLE_VALUE;
}

void LDL::Core::Windows::Directory::Close()
{
    FindClose(_File);
}

bool LDL::Core::Windows::Directory::Next(LDL::Core::FileInfo& fileInfo)
{
    BOOL result = FindNextFile(_File, &_Data);

    if (result)
        fileInfo.Name(_Data.cFileName);

    return result;
}