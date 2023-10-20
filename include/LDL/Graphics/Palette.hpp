#ifndef LDL_Graphics_Palette_hpp
#define LDL_Graphics_Palette_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Color.hpp>

namespace LDL
{
	namespace Graphics
	{
		class LDL_LIBRARY Palette
		{
		public:
			enum
			{
				Max = 256
			};
			Palette();
			Color* Colors();
			size_t Count();
		private:
			Color _Colors[Max];
		};
	}
}

#endif    