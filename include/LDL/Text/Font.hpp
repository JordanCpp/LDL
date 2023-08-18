#ifndef LDL_Text_Font_hpp
#define LDL_Text_Font_hpp

#include <LDL/Text/RasterizerContext.hpp>

namespace LDL
{
	namespace Text
	{
		class FontImpl;

		class LDL_LIBRARY Font : public LDL::Core::FastPimpl
		{
		public:
			Font(RasterizerContext* rasterizerContext,size_t fontSize, uint8_t* font, size_t size);
			~Font();
			FontImpl* GetFontImpl();
		private:
			FontImpl* _FontImpl;
		};
	}
}

#endif    
