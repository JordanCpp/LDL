// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/FStream.hpp>
#include <LDL/WinNT/Windows.hpp>
#include <LDL/WinNT/FStream.hpp>

LDL_FileStream::LDL_FileStream(LDL_Result& result) :
    _isOpen(false),
    _result(result),
	_handle(INVALID_HANDLE_VALUE)
{
}

LDL_FileStream::~LDL_FileStream()
{
	Close();
}

bool LDL_FileStream::Open(const char* path, size_t mode)
{
    Close();

    DWORD access = 0;
    DWORD disp   = 0;
    DWORD flags  = FILE_ATTRIBUTE_NORMAL;

    if (mode & ModeRead)
    {
        access |= GENERIC_READ;
    }

    if (mode & ModeWrite)
    {
        access |= GENERIC_WRITE;
    }

    if (mode & ModeAppend)
    {
        disp = OPEN_ALWAYS;
    }
    else if (mode & ModeCreate)
    {
        disp = CREATE_ALWAYS;
    }
    else if (mode & ModeWrite)
    {
        disp = OPEN_EXISTING;
    }
    else
    {
        disp = OPEN_EXISTING;
    }

    _handle = CreateFile(path, access, 0, NULL, disp, flags, NULL);

    _isOpen = (_handle != INVALID_HANDLE_VALUE);

    if (_isOpen && (mode & ModeAppend))
    {
        SetFilePointer(_handle, 0, NULL, FILE_END);
    }

    return _isOpen;
}

void LDL_FileStream::Close()
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

bool LDL_FileStream::IsOpen() const
{
    return _isOpen;
}

size_t LDL_FileStream::Read(void* buffer, size_t size)
{
    if (!_isOpen || !buffer || size == 0) 
    {
        return 0;
    }

    DWORD bytes = 0;
    BOOL result = ReadFile(_handle, buffer, (DWORD)(size), &bytes, NULL);

    return result ? (size_t)(bytes) : 0;
}

size_t LDL_FileStream::Write(const void* buffer, size_t size)
{
    if (!_isOpen || !buffer || size == 0) 
    {
        return 0;
    }

    DWORD bytes = 0;
    BOOL result = WriteFile(_handle, buffer, (DWORD)(size), &bytes, NULL);

    return result ? (size_t)(bytes) : 0;
}

bool LDL_FileStream::Flush()
{
    if (!_isOpen) return false;

    return FlushFileBuffers(_handle) != 0;
}

bool LDL_FileStream::Seek(size_t pos)
{
    if (!_isOpen) return false;

    return SetFilePointer(_handle, (LONG)(pos), 0, FILE_BEGIN) != INVALID_SET_FILE_POINTER;
}

size_t LDL_FileStream::Tell() const
{
    if (!_isOpen) return 0;

    return SetFilePointer(_handle, 0, 0, FILE_CURRENT);
}

size_t LDL_FileStream::Size() const
{
    if (!_isOpen)
    {
        return 0;
    }

    DWORD highPart = 0;
    DWORD lowPart  = 0;

    if (GetFileSize(_handle, &lowPart) == INVALID_FILE_SIZE)
    {
        if (GetLastError() != 0)
        {
            return 0;
        }
    }

    ULARGE_INTEGER fileSize;
    fileSize.HighPart = highPart;
    fileSize.LowPart  = lowPart;

    return (size_t)(fileSize.QuadPart);
}

LDL_IFileStream* LDL_CreateFileStream(LDL_Result& result)
{
    return new LDL_FileStream(result);
}
