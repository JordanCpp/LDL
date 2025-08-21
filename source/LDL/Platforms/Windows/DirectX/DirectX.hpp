#ifndef LDL_DirectX_DirectX_hpp
#define LDL_DirectX_DirectX_hpp

#include <windows.h>

#if _MSC_VER <= 1200 || __MINGW32__

typedef unsigned long ULONG_PTR, * PULONG_PTR;
typedef ULONG_PTR DWORD_PTR, * PDWORD_PTR;
#define HMONITOR HANDLE

#define _In_
#define _Outptr_
#define _Pre_null_
#define _In_opt_
#define _Out_opt_
#define _Out_writes_bytes_opt_(x)
#define _Out_
#define _Outptr_result_bytebuffer_(x)
#define _Outptr_opt_result_bytebuffer_(x)
#define _In_reads_bytes_(x)
#define _In_reads_bytes_opt_(x)
#define _In_reads_opt_(x)
#define _Out_writes_(x)
#define _Out_writes_opt_(x)
#endif

#endif
