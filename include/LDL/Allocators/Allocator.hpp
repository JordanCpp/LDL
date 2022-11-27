#ifndef LDL_Allocators_Allocator_hpp
#define LDL_Allocators_Allocator_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Allocators
	{
		class Allocator
		{
		public:
			enum
			{
				Kb = 1024,
				Mb = Kb * 1024,
				Gb = Mb * 1024
			};
			virtual void* Allocate(size_t bytes) = 0;
			virtual void Deallocate(void* ptr) = 0;
			virtual size_t UsedBytes() = 0;
			virtual void Reset() = 0;
		private:
		};
	}
}

#endif    