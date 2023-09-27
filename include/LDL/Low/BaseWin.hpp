#ifndef LDL_Low_BaseWindow_hpp
#define LDL_Low_BaseWindow_hpp

#include <LDL/Low/Vec2u.hpp>
#include <LDL/Low/String.hpp>

class LDL_LIBRARY LDL_BaseWindow
{
public:
	LDL_BaseWindow(const LDL_Vec2u& pos, const LDL_Vec2u& size, const char* title);
	~LDL_BaseWindow();
	const LDL_Vec2u& Pos();
	const LDL_Vec2u& Size();
	void Size(const LDL_Vec2u& size);
	const char* Title();
	void Title(const char* source);
private:
	LDL_Vec2u _Pos;
	LDL_Vec2u _Size;
	LDL_String _Title;
};

#endif
