#ifndef LDL_Events_Resize_hpp
#define LDL_Events_Resize_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Events
	{
		class Resize
		{
		public:
			uint8_t Type;
			size_t Width;
			size_t Height;
		};
	}
}

#endif