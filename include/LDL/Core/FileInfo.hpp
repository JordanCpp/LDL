#ifndef LDL_Core_FileInfo_hpp
#define LDL_Core_FileInfo_hpp

#include <LDL/Config.hpp>
#include <string>

namespace LDL
{
	namespace Core
	{
		class LDL_EXPORT FileInfo
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