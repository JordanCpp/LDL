// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_FileStream_hpp
#define LDL_Core_FileStream_hpp

#include <LDL/std/stddef.hpp>

namespace LDL
{
	class FileStream
	{
	public:
		enum
		{
			OpenModeRead = 1,
			OpenModeWrite = 2,
			OpenModeAppend = 4,
			OpenModeCreate = 8
		};

		FileStream();
		~FileStream();
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
		bool   _isOpen;
		void* _handle;
	};
}

#endif
