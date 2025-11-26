// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Win9X_FStreamI_hpp
#define LDL_Win9X_FStreamI_hpp

#include <LDL/FStream.hpp>
#include <LDL/Win9X/Windows.hpp>
#include <LDL/Win9X/WinError.hpp>

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
	HANDLE      _handle;
};

#endif
