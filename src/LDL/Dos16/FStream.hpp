// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Dos16_FStream_hpp
#define LDL_Dos16_FStream_hpp

#include <LDL/FStream.hpp>

class LDL_FileStream : public LDL_IFileStream
{
public:
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
	bool        _isOpen;
	LDL_Result& _result;
};

#endif
