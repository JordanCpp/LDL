/*
Copyright(C) 2026 Evgeny Zoshchuk (JordanCpp)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

#ifndef LDL_Render_Texture_H
#define LDL_Render_Texture_H

#include <LDL/Texture.h>
#include <LDL/Context.h>
#include <LDL/Renders/GL1/TexGL1.h>

typedef struct LDL_Texture
{
	LDL_Context*        Context;
	LDL_TextureOpenGL1* TextureOpenGL1;
} LDL_Texture;

#endif