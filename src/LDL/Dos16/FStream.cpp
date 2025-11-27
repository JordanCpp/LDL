// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Dos16/FStream.hpp>

LDL_FileStream::LDL_FileStream(LDL_Result& result) :
    _result(result),
    _isOpen(false)
{
}

LDL_FileStream::~LDL_FileStream()
{
    Close();
}

bool LDL_FileStream::Open(const char* path, size_t mode)
{
    Close();

    return _isOpen;
}

void LDL_FileStream::Close()
{
}

bool LDL_FileStream::IsOpen() const
{
    return _isOpen;
}

size_t LDL_FileStream::Read(void* buffer, size_t size)
{
    return 0;
}

size_t LDL_FileStream::Write(const void* buffer, size_t size)
{
    return 0;
}

bool LDL_FileStream::Flush()
{
    return false;
}

bool LDL_FileStream::Seek(size_t pos)
{
    return false;
}

size_t LDL_FileStream::Tell() const
{
    return 0;
}

size_t LDL_FileStream::Size() const
{
    return 0;
}

LDL_IFileStream* LDL_CreateFileStream(LDL_Result& result)
{
    return new LDL_FileStream(result);
}