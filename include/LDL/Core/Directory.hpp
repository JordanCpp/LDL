#ifndef LDL_Core_Directory_hpp
#define LDL_Core_Directory_hpp

#if defined(WIN32) || defined(WIN64)
#include <LDL/Platforms/Windows/Core/Directory.hpp>
namespace LDL
{
	namespace Core
	{
		typedef LDL::Core::Windows::Directory Directory;
	}
}
#else
#error Not implementation: Core::Directory
#endif

#endif 