#include <LDL/APIs/DirectX6/DirectX6Loader.hpp>

using namespace LDL::DirectX6;

DirectX6Loader::DirectX6Loader():
	_ddraw("ddraw.dll")
{
	DirectDrawCreate = (PFN_DirectDrawCreate)_ddraw.Function("DirectDrawCreate");
}