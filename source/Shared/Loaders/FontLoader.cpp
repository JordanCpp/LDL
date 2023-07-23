#include <LDL/Loaders/FontLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <stdio.h>

using namespace LDL::Loaders;

FontLoader::FontLoader(LDL::Allocators::Allocator* allocator) :
    _Allocator(allocator),
	_Buffer(NULL)
{
}

FontLoader::~FontLoader()
{
}

void FontLoader::Clear()
{
    _Buffer = NULL;
    _Allocator->Reset();
}

void FontLoader::Load(const std::string& path)
{
    if (path.empty())
        throw LDL::Core::RuntimeError("Argument path is empty");

    FILE* file = fopen(path.c_str(), "rb");

    if (file == NULL)
        throw LDL::Core::RuntimeError("Not load " + path);

    fseek(file, 0, SEEK_END);
    size_t bytes = ftell(file);
    fseek(file, 0, SEEK_SET);

    _Buffer = (uint8_t*)_Allocator->Allocate(bytes);

    fread(_Buffer, bytes, 1, file);

    fclose(file);
}

uint8_t* FontLoader::Font()
{
    return _Buffer;
}

size_t FontLoader::Size()
{
    return _Allocator->UsedBytes();
}
