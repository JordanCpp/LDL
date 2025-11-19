// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_FileStream_hpp
#define LDL_FileStream_hpp

#include <LDL/Types.hpp>
#include <LDL/Result.hpp>

class FileStreamImpl;

class LDL_FileStream
{
public:
	enum
	{
		SizeOf = 32,
		OpenModeRead = 1,
		OpenModeWrite = 2,
		OpenModeAppend = 4,
		OpenModeCreate = 8
	};

	LDL_FileStream(LDL_Result& result);
	~LDL_FileStream();
	bool Open(const char* path, size_t mode);
	void Close();
	bool IsOpen() const;
	size_t Read(void* buffer, size_t size);
	size_t Write(const void* buffer, size_t size);
	bool Flush();
	bool Seek(size_t pos);
	size_t Tell() const;
	size_t Size() const;
private:
	FileStreamImpl* _impl;
	uint8_t         _memory[SizeOf];
};

#endif
