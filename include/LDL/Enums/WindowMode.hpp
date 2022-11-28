#ifndef LDL_Enums_WindowMode_hpp
#define LDL_Enums_WindowMode_hpp

namespace LDL
{
	namespace Enums
	{
		class WindowMode
		{
		public:
			enum
			{
				Resized = 1,
				Fixed,
				FullScreen
			};
		};
	}
}

#endif