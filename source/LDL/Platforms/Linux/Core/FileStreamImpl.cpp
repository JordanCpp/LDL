// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/FileStream.hpp>
#include <LDL/Platforms/Linux/Core/FileStreamImpl.hpp>

using namespace LDL;

FileStreamImpl::FileStreamImpl(Result& result) :
	_isOpen(false),
    _result(result)
{
}

FileStreamImpl::~FileStreamImpl()
{
	Close();
}

bool FileStreamImpl::Open(const char* path, size_t mode)
{
    Close();

    return _isOpen;
}

void FileStreamImpl::Close()
{
}

bool FileStreamImpl::IsOpen() const
{
    return _isOpen;
}

size_t FileStreamImpl::Read(void* buffer, size_t size)
{
    return 0;
}

size_t FileStreamImpl::Write(const void* buffer, size_t size)
{
    return 0;
}

bool FileStreamImpl::Flush()
{
    return false;
}

bool FileStreamImpl::Seek(size_t pos)
{
    return false;
}

size_t FileStreamImpl::Tell() const
{
    return false;
}

size_t FileStreamImpl::Size() const
{
    return 0;
}
