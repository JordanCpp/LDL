#ifndef LDL_Core_Directory_hpp
#define LDL_Core_Directory_hpp

#include <LDL/Core/FileInfo.hpp>

namespace LDL
{
	namespace Core
	{
		class DirectoryImpl;

		class Directory
		{
		public:
			Directory();
			~Directory();
			bool Create(const std::string& path);
			bool Exist(const std::string& path);
			bool Delete(const std::string& path);
			bool Open(const std::string& path);
			void Close();
			bool Next(LDL::Core::FileInfo& fileInfo);
		private:
			DirectoryImpl* _DirectoryImpl;
		};
	}
}

#endif    