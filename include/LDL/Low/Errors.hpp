#ifndef LDL_Low_Errors_hpp
#define LDL_Low_Errors_hpp

#include <LDL/Low/Config.hpp>
#include <LDL/Low/Types.hpp>

LDL_LIBRARY bool LDL_IsError();
LDL_LIBRARY const char* LDL_GetError();
LDL_LIBRARY void LDL_AddError(const char* error);
LDL_LIBRARY void LDL_AddError(const char* error, const char* detail);
LDL_LIBRARY void LDL_Alert(const char* error);

#endif    