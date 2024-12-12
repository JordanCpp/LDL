#ifndef LDL_Loaders_FontLoader_hpp
#define LDL_Loaders_FontLoader_hpp

#include <LDL/Allocators/Allocator.hpp>
#include <string>

namespace LDL
{
	namespace Loaders
	{
		class LDL_LIBRARY FontLoader
		{
		public:
			FontLoader(LDL::Allocators::Allocator* allocator);
			~FontLoader();
			void Clear();
			void Load(const std::string& path);
			uint8_t* Font();
			size_t Size();
		private:
			LDL::Allocators::Allocator* _allocator;
			uint8_t* _buffer;
		};
	}
}

#endif     
