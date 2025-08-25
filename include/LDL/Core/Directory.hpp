// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Directory_hpp
#define LDL_Core_Directory_hpp

#include <LDL/Core/FileInfo.hpp>
#include <LDL/Core/Result.hpp>

namespace LDL
{
	namespace Core
	{
		class DirectoryImpl;

		class LDL_LIBRARY Directory
		{
		public:
			Directory(Result& result);
			~Directory();
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
			Result&        _result;
			DirectoryImpl* _impl;
		};
	}
}

#endif    
