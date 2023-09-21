#ifndef LDL_Low_String_hpp
#define LDL_Low_String_hpp

#include <LDL/Low/Types.hpp>

class LDL_String
{
public:
	LDL_String();
	LDL_String(const char* elements);
	~LDL_String();
	void Clear();
	const char* CStr();
	size_t Capacity();
	size_t Size();
	void Reserve(size_t count);
	void Resize(size_t count);
	void Append(const char& element);
	void Append(const char* elements);
	void Assign(const char* elements);
private:
	char* _Content;
	size_t _Capacity;
	size_t _Position;
};

#endif
