#include <LDL/APIs/Glide/Glide.hpp>

namespace LDL
{
	namespace Glide
	{
		PFN_grGlideInit grGlideInit = NULL;
		PFN_grGlideShutdown grGlideShutdown = NULL;
		PFN_grSstSelect grSstSelect = NULL;
		PFN_grSstWinOpen grSstWinOpen = NULL;
		PFN_grVertexLayout grVertexLayout = NULL;
		PFN_grColorCombine grColorCombine = NULL;
		PFN_grBufferClear grBufferClear = NULL;
		PFN_grBufferSwap grBufferSwap = NULL;
		PFN_grDrawLine grDrawLine = NULL;
		PFN_grConstantColorValue grConstantColorValue = NULL;
	}
}
