// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/New.hpp>
#include <LDL/Stream.hpp>

#if defined(LDL_WINDOWS_NT)
    #include <LDL/WinNT/FStreamI.hpp>
#elif defined(LDL_WINDOWS_9X)
    #include <LDL/Win9X/FStreamI.hpp>
#elif defined(__unix__)
    #include <LDL/Linux/FStreamI.hpp>
#else
    #include <LDL/Null/FStreamI.hpp>
#endif

LDL_FileStream::LDL_FileStream(LDL_Result& result) :
    _impl(new(_memory) FileStreamImpl(result))
{
}

LDL_FileStream::~LDL_FileStream()
{
    _impl->Close();
    
    //_impl->~FileStreamImpl();
}

bool LDL_FileStream::Open(const char* path, size_t mode)
{
    return _impl->Open(path, mode);
}

void LDL_FileStream::Close()
{
    _impl->Close();
}

bool LDL_FileStream::IsOpen() const
{
    return _impl->IsOpen();
}

size_t LDL_FileStream::Read(void* buffer, size_t size)
{
    return _impl->Read(buffer, size);
}

size_t LDL_FileStream::Write(const void* buffer, size_t size)
{
    return _impl->Write(buffer, size);
}

bool LDL_FileStream::Flush()
{
    return _impl->Flush();
}

bool LDL_FileStream::Seek(size_t pos)
{
    return _impl->Seek(pos);
}

size_t LDL_FileStream::Tell() const
{
    return _impl->Tell();
}

size_t LDL_FileStream::Size() const
{
    return _impl->Size();
}
