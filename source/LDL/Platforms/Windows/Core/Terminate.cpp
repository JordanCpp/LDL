#include <LDL/Core/Terminate.hpp>
#include "../Windows.hpp"

LDL_LIBRARY void LDL::Core::Terminate()
{
	ExitProcess(0);
}
