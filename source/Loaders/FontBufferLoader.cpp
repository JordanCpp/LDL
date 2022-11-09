#include <LDL/Loaders/FontBufferLoader.hpp>
#include <LDL/Core/RuntimeError.hpp>
#include <cstdio>

LDL::Loaders::FontBufferLoader::FontBufferLoader(LDL::Allocators::Allocator* allocator) :
    _Allocator(allocator),
	_Buffer(NULL)
{
}

LDL::Loaders::FontBufferLoader::~FontBufferLoader()
{
}

void LDL::Loaders::FontBufferLoader::Clear()
{
    _Buffer = NULL;
    _Allocator->Reset();
}

void LDL::Loaders::FontBufferLoader::Load(const std::string& path)
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

uint8_t* LDL::Loaders::FontBufferLoader::Font()
{
    return _Buffer;
}

size_t LDL::Loaders::FontBufferLoader::Size()
{
    return _Allocator->UsedBytes();
}