// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Core_DirectoryImpl_hpp
#define LDL_Platforms_Windows_Core_DirectoryImpl_hpp

#include <LDL/Core/Directory.hpp>
#include <LDL/Core/FileInfo.hpp>
#include <LDL/Platforms/Win9X/Windows.hpp>

namespace LDL
{
	class DirectoryImpl
	{
	public:
		DirectoryImpl(Result& result);
		const char* AllFiles();
		bool Create(const char* path);
		bool DirExist(const char* path);
		bool FileExist(const char* path);
		bool Delete(const char* path);
		bool Open(const char* path);
		void Close();
		bool Next(FileInfo& fileInfo);
		bool Remove(const char* path);
	private:
		Result&         _result;
		char            _allFiles[4];
		HANDLE          _file;
		WIN32_FIND_DATA _data;
	};
}

#endif
