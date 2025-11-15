// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/New.hpp>
#include <LDL/Core/FileStream.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/Platforms/WinNT/Core/FileStreamImpl.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Platforms/Win9X/Core/FileStreamImpl.hpp>
#elif defined(__unix__)
    #include <LDL/Platforms/Linux/Core/FileStreamImpl.hpp>
#endif

using namespace LDL;

FileStream::FileStream(Result& result) :
    _impl(new(_memory) FileStreamImpl(result))
{
}

FileStream::~FileStream()
{
    _impl->Close();
    
    _impl->~FileStreamImpl();
}

bool FileStream::Open(const char* path, size_t mode)
{
    return _impl->Open(path, mode);
}

void FileStream::Close()
{
    _impl->Close();
}

bool FileStream::IsOpen() const
{
    return _impl->IsOpen();
}

size_t FileStream::Read(void* buffer, size_t size)
{
    return _impl->Read(buffer, size);
}

size_t FileStream::Write(const void* buffer, size_t size)
{
    return _impl->Write(buffer, size);
}

bool FileStream::Flush()
{
    return _impl->Flush();
}

bool FileStream::Seek(size_t pos)
{
    return _impl->Seek(pos);
}

size_t FileStream::Tell() const
{
    return _impl->Tell();
}

size_t FileStream::Size() const
{
    return _impl->Size();
}
