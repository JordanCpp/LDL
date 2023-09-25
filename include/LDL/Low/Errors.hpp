#ifndef LDL_Low_Errors_hpp
#define LDL_Low_Errors_hpp

bool LDL_IsError();
const char* LDL_GetError();
void LDL_AddError(const char* error);
void LDL_AddError(const char* error, const char* detail);

#endif    