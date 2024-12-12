#ifndef LDL_Allocators_FixedLinear_hpp
#define LDL_Allocators_FixedLinear_hpp

#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Allocators
	{
		class LDL_LIBRARY FixedLinear : public Allocator
		{
		public:
			FixedLinear(size_t bytes, Allocator* allocator = NULL);
			~FixedLinear();
			void* Allocate(size_t bytes);
			void Deallocate(void* ptr);
			void Reset();
			size_t UsedBytes();
		private:
			size_t     _capacity;
			size_t     _position;
			uint8_t*   _content;
			Allocator* _allocator;
		};
	}
}

#endif  
