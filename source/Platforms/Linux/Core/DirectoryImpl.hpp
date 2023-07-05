#ifndef LDL_Platforms_Windows_Core_DirectoryImpl_hpp
#define LDL_Platforms_Windows_Core_DirectoryImpl_hpp

#include <LDL/Core/Directory.hpp>
#include <LDL/Core/FileInfo.hpp>
#include <dirent.h>

namespace LDL
{
	namespace Core
	{
		class DirectoryImpl
		{
		public:
			bool Create(const std::string& path);
			bool Exist(const std::string& path);
			bool Delete(const std::string& path);
			bool Open(const std::string& path);
			void Close();
			bool Next(FileInfo& fileInfo);
			bool Remove(const std::string& path);
		private:
		    DIR * _Directory;
		};
	}
}

#endif    