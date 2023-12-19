#ifndef LDL_Glide_3dfx_hpp
#define LDL_Glide_3dfx_hpp

namespace LDL
{
	namespace Glide
	{
		typedef unsigned char   FxU8;
		typedef signed   char   FxI8;
		typedef unsigned short  FxU16;
		typedef signed   short  FxI16;
		typedef signed   long   FxI32;
		typedef unsigned long   FxU32;
		typedef int             FxBool;
		typedef float           FxFloat;
		typedef double          FxDouble;

		typedef unsigned long                FxColor_t;
		typedef struct { float r, g, b, a; } FxColor4;

		const FxBool FXTRUE = 1;
		const FxBool FXFALSE = 0;
	}
}

#endif  