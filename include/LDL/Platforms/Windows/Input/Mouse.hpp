#ifndef LDL_Platforms_Windows_Input_Mouse_hpp
#define LDL_Platforms_Windows_Input_Mouse_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Input
	{
		namespace Windows
		{
			class Mouse
			{
			public:
				const LDL::Graphics::Point2u& Pos();
			private:
				LDL::Graphics::Point2u _Pos;
			};
		}
	}
}
#endif     