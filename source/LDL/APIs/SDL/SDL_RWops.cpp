// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <stdio.h>
#include <LDL/APIs/SDL/SDL_rwops.h>
#include <LDL/APIs/SDL/SDL_stdinc.h>
#include <LDL/APIs/SDL/SDL_error.h>

struct SDL_RWops
{
	enum
	{
		IsFile,
		IsMemory
	};
	uint8_t* data;
	size_t   type;
	FILE*    file;
	size_t   size;
	size_t   offset;
};

SDL_RWops* SDL_RWFromFile(const char* file, const char* mode)
{
	SDL_RWops* context = (SDL_RWops*)SDL_malloc(sizeof(SDL_RWops));

	context->file = fopen(file, mode);

	if (context->file == NULL)
	{
		SDL_free(context);

		SDL_SetError("Can't open file: %s\n", file);
	}
	else
	{
		context->type = SDL_RWops::IsFile;
	}

	return context;
}

SDL_RWops* SDL_RWFromMem(void* mem, int size)
{
	SDL_RWops* context = (SDL_RWops*)SDL_malloc(sizeof(SDL_RWops));

	context->type   = SDL_RWops::IsMemory;
	context->data   = (uint8_t*)mem;
	context->offset = 0;
	
	return context;
}

void SDL_RWclose(SDL_RWops* context)
{
	if (context && context->file)
	{
		fclose(context->file);
	}
}
int SDL_RWseek(SDL_RWops* context, int offset, int whence)
{
	int seek = 0;

	switch (whence) 
	{
	case RW_SEEK_SET:
		seek = SEEK_SET;
		break;
	case RW_SEEK_CUR:
		seek = SEEK_CUR;
		break;
	case RW_SEEK_END:
		seek = SEEK_END;
		break;
	default:
		SDL_SetError("Unknown value for 'whence'");
		return -1;
	}

	return fseek(context->file, offset, seek);
}

int SDL_RWread(SDL_RWops* context, void* ptr, int size, int maxnum)
{
	return fread(ptr, size, maxnum, context->file);
}

int SDL_RWwrite(struct SDL_RWops* context, const void* ptr, int size, int num)
{
	return fwrite(ptr, size, num, context->file);
}

int SDL_RWtell(SDL_RWops* context)
{
	return fseek(context->file, 0, SEEK_CUR);
}
