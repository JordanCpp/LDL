#ifndef LDL_Glide_GlideLoader_hpp
#define LDL_Glide_GlideLoader_hpp

#include <LDL/APIs/Glide/Glide.hpp>
#include <LDL/Core/Library.hpp>

namespace LDL
{
	namespace Glide
	{
		class LDL_LIBRARY GlideLoader
		{
		public:
			GlideLoader();
			~GlideLoader();
		private:
			Core::Library _Glide;
		};
	}
}

#endif   
