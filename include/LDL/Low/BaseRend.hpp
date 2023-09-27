#ifndef LDL_Low_BaseRender_hpp
#define LDL_Low_BaseRender_hpp

#include <LDL/Low/Vec2u.hpp>
#include <LDL/Low/Color.hpp>

class LDL_LIBRARY LDL_BaseRender
{
public:
	LDL_BaseRender(const LDL_Vec2u& size);
	const LDL_Vec2u& Size();
	const LDL_Color& Color();
	void SetColor(const LDL_Color& color);
private:
	LDL_Vec2u _Size;
	LDL_Color   _Color;
};

#endif
