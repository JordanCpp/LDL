#ifndef LDL_Text_RasterizerContext_hpp
#define LDL_Text_RasterizerContext_hpp

#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Text
	{
		class RasterizerContextImpl;

		class LDL_EXPORT RasterizerContext : public LDL::Core::FastPimpl
		{
		public:
			RasterizerContext();
			~RasterizerContext();
			RasterizerContextImpl* GetRasterizerContextImpl();
		private:
			RasterizerContextImpl* _RasterizerContextImpl;
		};
	}
}

#endif    
