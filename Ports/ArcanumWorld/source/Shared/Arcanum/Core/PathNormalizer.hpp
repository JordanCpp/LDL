#ifndef Arcanum_Core_PathNormalizer_hpp
#define Arcanum_Core_PathNormalizer_hpp

#include <string>

namespace Arcanum
{
	namespace Core
	{
		class PathNormalizer
		{
		public:
			void Normalize(char* path);
			void Normalize(std::string& path);
		private:
		};
	}
}

#endif