// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_WinNT_Core_FileStreamImpl_hpp
#define LDL_Platforms_WinNT_Core_FileStreamImpl_hpp

#include <LDL/WinNT/WinError.hpp>
#include <LDL/WinNT/Windows.hpp>

class FileStreamImpl
{
public:
	enum
	{
		OpenModeRead = 1,
		OpenModeWrite = 2,
		OpenModeAppend = 4,
		OpenModeCreate = 8
	};

	FileStreamImpl(LDL_Result& result);
	~FileStreamImpl();
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
	LDL_Result& _result;
	bool    _isOpen;
	HANDLE  _handle;
};

#endif
