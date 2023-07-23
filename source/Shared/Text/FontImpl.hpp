#ifndef LDL_Text_FontImpl_hpp
#define LDL_Text_FontImpl_hpp

#include <LDL/Config.hpp>
#include <LDL/Core/Types.hpp>

#include <ft2build.h>
#include FT_FREETYPE_H 

#include "RasterizerContextImpl.hpp"

namespace LDL
{
	namespace Text
	{
		class LDL_EXPORT FontImpl
		{
		public:
			FontImpl(RasterizerContextImpl* rasterizerContextImpl, size_t fontSize, uint8_t* font, size_t size);
			~FontImpl();
			FT_Face GetFace();
		private:
			FT_Face _Face;
		};
	}
}

#endif    
