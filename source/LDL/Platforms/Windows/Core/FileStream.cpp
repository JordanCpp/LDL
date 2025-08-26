// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <Windows.h>
#include <LDL/Core/FileStream.hpp>

using namespace LDL::Core;

FileStream::FileStream() :
	_isOpen(false),
	_handle(INVALID_HANDLE_VALUE)
{
}

FileStream::~FileStream()
{
	Close();
}

bool FileStream::Open(const char* path, size_t mode)
{
    Close();

    DWORD access = 0;
    DWORD disp   = 0;
    DWORD flags  = FILE_ATTRIBUTE_NORMAL;

    if (mode & OpenModeRead)
    {
        access |= GENERIC_READ;
    }

    if (mode & OpenModeWrite)
    {
        access |= GENERIC_WRITE;
    }

    if (mode & OpenModeAppend)
    {
        disp = OPEN_ALWAYS;
    }
    else if (mode & OpenModeCreate)
    {
        disp = CREATE_ALWAYS;
    }
    else if (mode & OpenModeWrite)
    {
        disp = OPEN_EXISTING;
    }
    else
    {
        disp = OPEN_EXISTING;
    }

    _handle = CreateFile(path, access, 0, NULL, disp, flags, NULL);

    _isOpen = (_handle != INVALID_HANDLE_VALUE);

    if (_isOpen && (mode & OpenModeAppend))
    {
        SetFilePointer(_handle, 0, NULL, FILE_END);
    }

    return _isOpen;
}

void FileStream::Close()
{
    if (_isOpen)
    {

        if (_handle != INVALID_HANDLE_VALUE)
        {
            CloseHandle(_handle);
            _handle = INVALID_HANDLE_VALUE;
        }

        _isOpen = false;
    }
}

bool FileStream::IsOpen() const
{
    return _isOpen;
}

size_t FileStream::Read(void* buffer, size_t size)
{
    if (!_isOpen || !buffer || size == 0) 
    {
        return 0;
    }

    DWORD bytesRead = 0;
    BOOL result     = ReadFile(_handle, buffer, DWORD(size), &bytesRead, NULL);

    return result ? (size_t)(bytesRead) : 0;
}

size_t FileStream::Write(const void* buffer, size_t size)
{
    if (!_isOpen || !buffer || size == 0) 
    {
        return 0;
    }


    DWORD bytesWritten = 0;
    BOOL result        = WriteFile(_handle, buffer, static_cast<DWORD>(size), &bytesWritten, NULL);

    return result ? (size_t)(bytesWritten) : 0;
}

bool FileStream::Flush()
{
    if (!_isOpen) return false;

    return FlushFileBuffers(_handle) != 0;
}

bool FileStream::Seek(size_t pos)
{
    if (!_isOpen) return false;

    return SetFilePointer(_handle, (LONG)(pos), 0, FILE_BEGIN) != INVALID_SET_FILE_POINTER;
}

size_t FileStream::Tell() const
{
    if (!_isOpen) return 0;

    return SetFilePointer(_handle, 0, 0, FILE_CURRENT);
}

size_t FileStream::Size() const 
{
    if (!_isOpen) return 0;

    LARGE_INTEGER sz;

    if (!GetFileSizeEx(_handle, &sz)) return 0;

    return (size_t)(sz.QuadPart);
}
