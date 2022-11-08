#ifndef LDL_Loaders_FontBufferLoader_hpp
#define LDL_Loaders_FontBufferLoader_hpp

#include <LDL/Allocators/Allocator.hpp>
#include <string>

namespace LDL
{
	namespace Loaders
	{
		class FontBufferLoader
		{
		public:
			FontBufferLoader(LDL::Allocators::Allocator* allocator);
			~FontBufferLoader();
			void Clear();
			void Load(const std::string& path);
			uint8_t* Font();
			size_t Size();
		private:
			LDL::Allocators::Allocator* _Allocator;
			uint8_t* _Buffer;
		};
	}
}

#endif     