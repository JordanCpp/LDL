/*
Copyright(C) 2026 AslanD (Ztry8)

This library is free software; you can redistribute it and /or modify it
under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.See the GNU Lesser General Public
License for more details.
*/

/*
 * Dynamic library loader for the Emscripten backend.
 *
 * WebAssembly has no shared-library runtime in the traditional sense.
 * Emscripten provides a dlopen() emulation when the main module is
 * built with -sMAIN_MODULE=1 and side modules with -sSIDE_MODULE=1,
 * but that is an opt-in feature.
 *
 * For the common case (no side modules) LDL_LibraryOpen is a no-op
 * that records the path for diagnostic purposes.
 * LDL_LibraryGetFunction resolves symbols through dlsym(RTLD_DEFAULT),
 * which Emscripten maps to the combined wasm symbol table of all linked
 * modules, which are sufficient for resolving OpenGL entry points that the
 * toolchain links statically.
 *
 * Note on typedef:
 *   Library.h declares `typedef struct LDL_Library LDL_Library` as a
 *   forward declaration.  We must NOT repeat `typedef` here; just
 *   provide the struct body.  Re-declaring typedef is only valid in C11
 *   and we target C89/C99 compatibility for old-iron builds.
 */

#include <stdlib.h>
#include <dlfcn.h>
#include <LDL/Library.h>

struct LDL_Library
{
    LDL_Result* Result;
    void*       Handle;
};

LDL_Library* LDL_LibraryCreate(LDL_Result* result)
{
    LDL_Library* library = (LDL_Library*)malloc(sizeof(LDL_Library));

    if (library)
    {
        library->Result = result;
        library->Handle = NULL;
        return library;
    }

    return NULL;
}

void LDL_LibraryDestroy(LDL_Library* library)
{
    if (library)
    {
        LDL_LibraryClose(library);
        free(library);
    }
}

bool LDL_LibraryOpen(LDL_Library* library, const char* path)
{
    if (!library || !path)
        return false;

    LDL_LibraryClose(library);

    library->Handle = dlopen(path, RTLD_NOW | RTLD_GLOBAL);

    if (!library->Handle)
    {
        if (library->Result)
        {
            LDL_ResultAddMessage(library->Result,
                "Load library failed: %s\n", path);
        }
        return false;
    }

    return true;
}

void LDL_LibraryClose(LDL_Library* library)
{
    if (library && library->Handle)
    {
        dlclose(library->Handle);
        library->Handle = NULL;
    }
}

LDL_VoidFuncPtr LDL_LibraryGetFunction(LDL_Library* library,
                                        const char* name)
{
    LDL_VoidFuncPtr ptr = NULL;

    if (!library || !name)
        return NULL;

    if (library->Handle)
    {
        ptr = (LDL_VoidFuncPtr)dlsym(library->Handle, name);
    }
    else
    {
        /* No explicit handle: search the combined wasm symbol table */
        ptr = (LDL_VoidFuncPtr)dlsym(RTLD_DEFAULT, name);
    }

    if (!ptr && library->Result)
    {
        LDL_ResultAddMessage(library->Result,
            "GetProcAddress failed: %s\n", name);
    }

    return ptr;
}
