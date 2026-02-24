// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/Core/Assert.hpp>
#include <LDL/Loaders/FontLoader.hpp>

using namespace LDL;

FontLoader::FontLoader(Allocator* allocator) :
    _allocator(allocator),
	_buffer(NULL)
{
}

FontLoader::~FontLoader()
{
}

void FontLoader::Clear()
{
    _buffer = NULL;
    _allocator->Reset();
}

void FontLoader::Load(const char* path)
{
    LDL_ASSERT_DETAIL(path != NULL, "Argument path is empty");

    FILE* file = fopen(path, "rb");

    _assert = "Not load ";
    _assert += path;

    LDL_ASSERT_DETAIL(file != NULL, _assert.c_str());

    fseek(file, 0, SEEK_END);
    size_t bytes = ftell(file);
    fseek(file, 0, SEEK_SET);

    _buffer = (uint8_t*)_allocator->Allocate(bytes);

    fread(_buffer, bytes, 1, file);

    fclose(file);
}

uint8_t* FontLoader::Font()
{
    return _buffer;
}

size_t FontLoader::Size()
{
    return _allocator->UsedBytes();
}
