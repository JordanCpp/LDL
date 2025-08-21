#ifndef LDL_Text_RasterizerContext_hpp
#define LDL_Text_RasterizerContext_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Text
	{
		class RasterizerContextImpl;

		class LDL_LIBRARY RasterizerContext
		{
		public:
			RasterizerContext();
			~RasterizerContext();
			RasterizerContextImpl* GetRasterizerContextImpl();
		private:
			RasterizerContextImpl* _impl;
		};
	}
}

#endif    
