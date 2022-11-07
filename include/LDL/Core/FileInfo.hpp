#ifndef LDL_Core_FileInfo_hpp
#define LDL_Core_FileInfo_hpp

#include <string>

namespace LDL
{
	namespace Core
	{
		class FileInfo
		{
		public:
			const std::string& Name();
			void Name(const std::string& source);
		private:
			std::string _Name;
		};
	}
}

#endif    