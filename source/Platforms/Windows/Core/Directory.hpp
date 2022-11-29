#ifndef LDL_Platforms_Windows_Core_Directory_hpp
#define LDL_Platforms_Windows_Core_Directory_hpp

#include <LDL/Core/IDirectory.hpp>
#include <Windows.h>
#include <LDL/Core/FileInfo.hpp>

namespace LDL
{
	namespace Core
	{
		namespace Windows
		{
			class Directory: public LDL::Core::IDirectory
			{
			public:
				bool Create(const std::string& path);
				bool Exist(const std::string& path);
				bool Delete(const std::string& path);
				bool Open(const std::string& path);
				void Close();
				bool Next(LDL::Core::FileInfo& fileInfo);
			private:
				HANDLE _File;
				WIN32_FIND_DATA _Data;
			};
		}
	}
}

#endif    