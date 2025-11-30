// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <LDL/StdFuncs.hpp>
#include <LDL/Linux/FStream.hpp>

LDL_FileStream::LDL_FileStream(LDL_Result& result) :
	_isOpen(false),
    _result(result),
    _fd(-1),
    _mode(0)
{
}

LDL_FileStream::~LDL_FileStream()
{
	Close();
}

bool LDL_FileStream::Open(const char* path, size_t mode)
{
    Close();

    if (path == NULL || path[0] == '\0')
    {
        _result.Message("Invalid file path");
        return false;
    }

    int flags = 0;
    mode_t permissions = 0644;

    if ((mode & ModeRead) && (mode & ModeWrite))
    {
        flags = O_RDWR;
    }
    else if (mode & ModeRead)
    {
        flags = O_RDONLY;
    }
    else if (mode & ModeWrite)
    {
        flags = O_WRONLY;
    }

    if (mode & ModeCreate)
    {
        flags |= O_CREAT | O_TRUNC;
    }
    else if (mode & ModeAppend)
    {
        flags |= O_APPEND;
        if (mode & ModeWrite)
        {
            flags |= O_CREAT;
        }
    }

    _fd = open(path, flags, permissions);

    if (_fd == -1)
    {
        _result.Message(strerror(errno));
        return false;
    }

    struct stat fileStat;
    if (fstat(_fd, &fileStat) == 0)
    {
        _fileSize = fileStat.st_size;
    }

    _mode   = mode;
    _isOpen = true;

    return true;
}

void LDL_FileStream::Close()
{
    if (_isOpen && _fd != -1)
    {
        Flush();
        close(_fd);
        _fd = -1;
    }

    _isOpen   = false;
    _fileSize = 0;
    _mode     = 0;
}

bool LDL_FileStream::IsOpen() const
{
    return _isOpen && (_fd != -1);
}

size_t LDL_FileStream::Read(void* buffer, size_t size)
{
    if (!IsOpen() || !buffer || size == 0)
    {
        return 0;
    }

    if (!(_mode & ModeRead))
    {
        _result.Message("File not opened for reading");
        return 0;
    }

    ssize_t bytesRead = read(_fd, buffer, size);

    if (bytesRead == -1)
    {
        _result.Message(strerror(errno));
        return 0;
    }

    return (size_t)bytesRead;
}

size_t LDL_FileStream::Write(const void* buffer, size_t size)
{
    if (!IsOpen() || !buffer || size == 0)
    {
        return 0;
    }

    if (!(_mode & ModeWrite))
    {
        _result.Message("File not opened for writing");
        return 0;
    }

    ssize_t bytesWritten = write(_fd, buffer, size);

    if (bytesWritten == -1)
    {
        _result.Message(strerror(errno));
        return 0;
    }

    return (size_t)bytesWritten;
}

bool LDL_FileStream::Flush()
{
    if (!IsOpen())
    {
        return false;
    }

#ifdef __linux__
    return fsync(_fd) == 0;
#else
    return true;
#endif
}

bool LDL_FileStream::Seek(size_t pos)
{
    if (!IsOpen())
    {
        return false;
    }

    off_t result = lseek(_fd, (off_t)pos, SEEK_SET);

    if (result == (off_t)-1)
    {
        _result.Message(strerror(errno));
        return false;
    }

    return true;
}

size_t LDL_FileStream::Tell() const
{
    if (!IsOpen())
    {
        return 0;
    }

    off_t pos = lseek(_fd, 0, SEEK_CUR);

    if (pos == (off_t)-1)
    {
        return 0;
    }

    return (size_t)pos;
}

size_t LDL_FileStream::Size() const
{
    if (!IsOpen())
    {
        return 0;
    }

    struct stat fileStat;
    if (fstat(_fd, &fileStat) == 0)
    {
        return fileStat.st_size;
    }

    return 0;
}

LDL_IFileStream* LDL_CreateFileStream(LDL_Result& result)
{
    return new LDL_FileStream(result);
}
