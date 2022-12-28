#ifndef LDL_Loaders_OpenGLLoader_hpp
#define LDL_Loaders_OpenGLLoader_hpp

#include <LDL/Core/Library.hpp>

namespace LDL
{
	namespace Loaders
	{
		class OpenGLLoader
		{
		public:
			OpenGLLoader(size_t major, size_t minor);
			~OpenGLLoader();
		private:
			size_t _Major;
			size_t _Minor;
		};
	}
}

#endif      