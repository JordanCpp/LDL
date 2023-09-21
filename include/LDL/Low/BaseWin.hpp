#ifndef LDL_Low_BaseWindow_hpp
#define LDL_Low_BaseWindow_hpp

#include <LDL/Low/Point2u.hpp>
#include <LDL/Low/String.hpp>

class LDL_BaseWindow
{
public:
	LDL_BaseWindow(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title);
	const LDL_Point2u& Pos();
	const LDL_Point2u& Size();
	void Size(const LDL_Point2u& size);
	const char* Title();
	void Title(const char* source);
private:
	LDL_Point2u _Pos;
	LDL_Point2u _Size;
	LDL_String _Title;
};

#endif
