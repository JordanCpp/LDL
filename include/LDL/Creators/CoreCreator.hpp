#ifndef LDL_Creators_CoreCreator_hpp
#define LDL_Creators_CoreCreator_hpp

#include <LDL/Core/IDirectory.hpp>

namespace LDL
{
	namespace Creators
	{
		class CoreCreator
		{
		public:
			LDL::Core::IDirectory* CreateDir();
			void Destroy(LDL::Core::IDirectory* directory);
		};
	}
}

#endif    