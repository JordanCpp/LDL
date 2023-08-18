#ifndef LDL_FixedLinear_h
#define LDL_FixedLinear_h

#include <LDLC/LDL_Export.h>
#include <LDLC/LDL_Types.h>
#include <LDLC/LDL_Allocator.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LDL_FixedLinear LDL_FixedLinear;

LDL_LIBRARY LDL_FixedLinear* LDL_FixedLinearNew(size_t bytes, void* allocator);
LDL_LIBRARY void LDL_FixedLinearFree(LDL_FixedLinear* ptr);
LDL_LIBRARY void* LDL_FixedLinearAllocate(LDL_FixedLinear* fixedLinear, size_t bytes);
LDL_LIBRARY void LDL_FixedLinearDeallocate(LDL_FixedLinear* fixedLinear, void* ptr);
LDL_LIBRARY void LDL_FixedLinearReset(LDL_FixedLinear* fixedLinear);
LDL_LIBRARY size_t LDL_FixedLinearUsedBytes(LDL_FixedLinear* fixedLinear);

#ifdef __cplusplus
}
#endif

#endif
