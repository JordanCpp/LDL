#ifndef LDL_Allocators_FixedLinear_hpp
#define LDL_Allocators_FixedLinear_hpp

#include <LDL/Config.hpp>
#include <LDL/Allocators/Allocator.hpp>

namespace LDL
{
	namespace Allocators
	{
		class LDL_EXPORT FixedLinear : public LDL::Allocators::Allocator
		{
		public:
			FixedLinear(size_t bytes, LDL::Allocators::Allocator* allocator = NULL);
			~FixedLinear();
			void* Allocate(size_t bytes);
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