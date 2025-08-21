#include <LDL/APIs/Glide/GlideLoader.hpp>

using namespace LDL::Glide;

GlideLoader::GlideLoader() :
	_Glide("Glide3x.dll")
{
	grGlideInit = (PFN_grGlideInit)_Glide.Function("_grGlideInit@0");
	grGlideShutdown = (PFN_grGlideShutdown)_Glide.Function("_grGlideShutdown@0");
	grSstSelect = (PFN_grSstSelect)_Glide.Function("_grSstSelect@4");
	grSstWinOpen = (PFN_grSstWinOpen)_Glide.Function("_grSstWinOpen@28");
	grVertexLayout = (PFN_grVertexLayout)_Glide.Function("_grVertexLayout@12");
	grColorCombine = (PFN_grColorCombine)_Glide.Function("_grColorCombine@20");
	grBufferClear = (PFN_grBufferClear)_Glide.Function("_grBufferClear@12");
	grBufferSwap = (PFN_grBufferSwap)_Glide.Function("_grBufferSwap@4");
	grDrawLine = (PFN_grDrawLine)_Glide.Function("_grDrawLine@8");
	grConstantColorValue = (PFN_grConstantColorValue)_Glide.Function("_grConstantColorValue@4");
	
	
}

GlideLoader::~GlideLoader()
{
}
