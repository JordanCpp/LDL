// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_FStream_hpp
#define LDL_FStream_hpp

#include <LDL/Types.hpp>
#include <LDL/Result.hpp>

class LDL_IFileStream
{
public:
	enum
	{
		ModeRead   = 1,
		ModeWrite  = 2,
		ModeAppend = 4,
		ModeCreate = 8
	};
	virtual ~LDL_IFileStream() {};
	virtual bool Open(const char* path, size_t mode) = 0;
	virtual void Close() = 0;
	virtual bool IsOpen() const = 0;
	virtual size_t Read(void* buffer, size_t size) = 0;
	virtual size_t Write(const void* buffer, size_t size) = 0;
	virtual bool Flush() = 0;
	virtual bool Seek(size_t pos) = 0;
	virtual size_t Tell() const = 0;
	virtual size_t Size() const = 0;
};

LDL_IFileStream* LDL_CreateFileStream(LDL_Result& result);

#endif
