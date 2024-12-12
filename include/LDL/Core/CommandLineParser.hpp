#ifndef LDL_Core_CommandLineParser_hpp
#define LDL_Core_CommandLineParser_hpp

#include <vector>
#include <string>
#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Core
	{
		class LDL_LIBRARY CommandLineParser
		{
		public:
			CommandLineParser(size_t argc, char* argv[]);
			const std::vector<std::string>& Lines();
		private:
			std::vector<std::string> _lines;
		};
	}
}

#endif