// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Core_Directory_hpp
#define LDL_Core_Directory_hpp

#include <LDL/Core/FileInfo.hpp>

namespace LDL
{
	namespace Core
	{
		class DirectoryImpl;

		class LDL_LIBRARY Directory
		{
		public:
			Directory();
			~Directory();
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
			DirectoryImpl* _impl;
		};
	}
}

#endif    
