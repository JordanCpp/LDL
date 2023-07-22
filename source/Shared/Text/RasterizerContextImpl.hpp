#ifndef LDL_Text_RasterizerContextImpl_hpp
#define LDL_Text_RasterizerContextImpl_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H 

namespace LDL
{
	namespace Text
	{
		class LDL_EXPORT RasterizerContextImpl
		{
		public:
			RasterizerContextImpl();
			~RasterizerContextImpl();
			FT_Library GetLibrary();
		private:
			FT_Library _Library;
		};
	}
}

#endif    