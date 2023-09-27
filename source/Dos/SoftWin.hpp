#ifndef LDL_Dos_SoftWin_hpp
#define LDL_Dos_SoftWin_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/Eventer.hpp>
#include <LDL/Low/EHandler.hpp>
#include <LDL/Low/BaseWin.hpp>

class LDL_SoftWindow : public LDL_IWindow
{
public:
	LDL_SoftWindow(LDL_IRenderContext * context, const LDL_Vec2u& pos, const LDL_Vec2u& size, const char * title);
	~LDL_SoftWindow();
	bool Running();
	void Present();
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Vec2u& Size();
	const LDL_Vec2u& Pos();
private:
	bool InitMouse();
	bool MousePress(size_t button);
	LDL_BaseWindow _BaseWindow;
	LDL_IRenderContext* _Context;
	LDL_Eventer _Eventer;
};

#endif
