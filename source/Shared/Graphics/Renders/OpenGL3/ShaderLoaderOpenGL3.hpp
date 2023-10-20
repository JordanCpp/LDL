#ifndef LDL_Graphics_OpenGL3_ShaderLoader_hpp
#define LDL_Graphics_OpenGL3_ShaderLoader_hpp

#include <fstream>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class ShaderLoader
		{
		public:
			ShaderLoader();
			~ShaderLoader();
			bool Load(const std::string& path);
			const std::string& Result();
		private:
			std::fstream _File;
			std::string  _Result;
			std::string  _Line;
		};
	}
}

#endif    
