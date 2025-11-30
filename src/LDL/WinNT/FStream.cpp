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

    if ((mode & ModeWrite) && (mode & ModeRead)) 
    {
        if (mode & ModeCreate) 
        {
            disp = CREATE_ALWAYS;
        }
        else if (mode & ModeAppend) 
        {
            disp = OPEN_ALWAYS;
        }
        else 
        {
            disp = OPEN_EXISTING;
        }
    }
    else if (mode & ModeWrite) 
    {
        if (mode & ModeCreate) 
        {
            disp = CREATE_ALWAYS;
        }
        else if (mode & ModeAppend)
        {
            disp = OPEN_ALWAYS;
        }
        else 
        {
            disp = OPEN_EXISTING;
        }
    }
    else 
    {
        disp = OPEN_EXISTING;
    }

    _handle = CreateFileA(path, access, FILE_SHARE_READ, NULL, disp, flags, NULL);
    _isOpen = (_handle != INVALID_HANDLE_VALUE);

    if (!_isOpen) 
    {
        WindowError error;
        _result.Message(error.GetErrorMessage());
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
    return _isOpen && (_handle != INVALID_HANDLE_VALUE);
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

#ifdef _WIN64
    LONG high = (LONG)(pos >> 32);
    LONG low  = (LONG)(pos & 0xFFFFFFFF);
#else
    LONG high = 0;
    LONG low  = (LONG)pos;
#endif

    DWORD result = SetFilePointer(_handle, low, &high, FILE_BEGIN);

    return (result != INVALID_SET_FILE_POINTER) || (GetLastError() == NO_ERROR);
}

size_t LDL_FileStream::Tell() const
{
    if (!_isOpen) return 0;

    LONG  high = 0;
    DWORD low  = SetFilePointer(_handle, 0, &high, FILE_CURRENT);

    if (low == INVALID_SET_FILE_POINTER && GetLastError() != NO_ERROR)
    {
        return 0;
    }

#ifdef _WIN64
    return ((size_t)high << 32) | low;
#else
    if (high != 0) 
    {
        return 0xFFFFFFFF;
    }

    return low;
#endif
}

size_t LDL_FileStream::Size() const
{
    if (!_isOpen) return 0;

    DWORD high = 0;
    DWORD low = GetFileSize(_handle, &high);

    if (low == INVALID_FILE_SIZE && GetLastError() != NO_ERROR)
    {
        return 0;
    }

#ifdef _WIN64
    return ((size_t)high << 32) | low;
#else
    if (high != 0) 
    {
        return 0xFFFFFFFF;
    }
    return low;
#endif
}

LDL_IFileStream* LDL_CreateFileStream(LDL_Result& result)
{
    return new LDL_FileStream(result);
}
