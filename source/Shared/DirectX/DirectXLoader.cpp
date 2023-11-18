#include <LDL/DirectX/DirectXLoader.hpp>
#include <assert.h>

using namespace LDL::DirectX;
using namespace LDL::DirectX9;

#define D3D_SDK_VERSION 31 

LDL::DirectX::DirectXLoader::DirectXLoader() :
	_Library_d3d9("d3d9.dll")
{
}

LPDIRECT3D9 DirectXLoader::GetDirect3D()
{
	LPDIRECT3D9 result = NULL;

	Direct3DCreate9 = (PFNDirect3DCreate9)_Library_d3d9.Function("Direct3DCreate9");

	assert(Direct3DCreate9 != NULL);

	result = Direct3DCreate9(D3D_SDK_VERSION);

	assert(result != NULL);

	return result;
}
