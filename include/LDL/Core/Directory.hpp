#ifndef LDL_Core_Directory_hpp
#define LDL_Core_Directory_hpp

#include <LDL/Core/FileInfo.hpp>
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Core
	{
		class DirectoryImpl;

		class LDL_EXPORT Directory: public FastPimpl
		{
		public:
			Directory();
			~Directory();
			bool Create(const std::string& path);
			bool Exist(const std::string& path);
			bool Delete(const std::string& path);
			bool Open(const std::string& path);
			void Close();
			bool Next(FileInfo& fileInfo);
			bool Remove(const std::string& path);
		private:
			DirectoryImpl* _DirectoryImpl;
		};
	}
}

#endif    