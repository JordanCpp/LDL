#ifndef LDL_Core_IDirectory_hpp
#define LDL_Core_IDirectory_hpp

#include <LDL/Core/FileInfo.hpp>

namespace LDL
{
	namespace Core
	{
		class IDirectory
		{
		public:
		virtual	bool Create(const std::string& path) = 0;
		virtual	bool Exist(const std::string& path) = 0;
		virtual	bool Delete(const std::string& path) = 0;
		virtual	bool Open(const std::string& path) = 0;
		virtual	void Close() = 0;
		virtual	bool Next(LDL::Core::FileInfo& fileInfo) = 0;
		virtual ~IDirectory() {};
		};
	}
}

#endif    