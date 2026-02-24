// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Core_DirectoryImpl_hpp
#define LDL_Platforms_Windows_Core_DirectoryImpl_hpp

#include <LDL/Core/Directory.hpp>
#include <LDL/Core/FileInfo.hpp>
#include <LDL/Platforms/Windows/Windows.hpp>

namespace LDL
{
	class DirectoryImpl
	{
	public:
		const char* AllFiles();
		bool Create(const std::string& path);
		bool DirExist(const std::string& path);
		bool FileExist(const std::string& path);
		bool Delete(const std::string& path);
		bool Open(const std::string& path);
		void Close();
		bool Next(FileInfo& fileInfo);
		bool Remove(const std::string& path);
	private:
		char            _allFiles[4];
		HANDLE          _file;
		WIN32_FIND_DATA _data;
	};
}

#endif    
