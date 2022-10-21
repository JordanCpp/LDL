#ifndef LDL_Allocators_FixedLinear_hpp
#define LDL_Allocators_FixedLinear_hpp

#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Allocators
	{
		class FixedLinear : public LDL::Allocators::Allocator
		{
		public:
			FixedLinear(size_t bytes, LDL::Allocators::Allocator* allocator = nullptr);
			~FixedLinear();
			void* Allocate(size_t bytes);
			void* Reallocate(void* ptr, size_t bytes);
			void Deallocate(void* ptr);
			void Reset();
			size_t UsedBytes();
		private:
			size_t _Capacity;
			size_t _Position;
			uint8_t* _Content;
			LDL::Allocators::Allocator* _Allocator;
		};
	}
}

#endif  