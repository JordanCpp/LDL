#ifndef LDL_Core_FileInfo_hpp
#define LDL_Core_FileInfo_hpp

#include <LDL/Core/Types.hpp>
#include <string>

namespace LDL
{
	namespace Core
	{
		class LDL_LIBRARY FileInfo
		{
		public:
			const std::string& Name();
			void Name(const std::string& source);
		private:
			std::string _name;
		};
	}
}

#endif
