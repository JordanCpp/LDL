#ifndef LDL_Dos_SoftWin_hpp
#define LDL_Dos_SoftWin_hpp

#include <LDL/Low/Abstract.hpp>
#include <LDL/Low/Eventer.hpp>
#include <LDL/Low/EHandler.hpp>
#include <LDL/Low/BaseWin.hpp>

class LDL_SoftWin : public LDL_IWindow
{
public:
	LDL_SoftWin(LDL_ErrorHandler* errorHandler, LDL_IRenderContext * context, const LDL_Point2u& pos, const LDL_Point2u& size, const char * title);
	~LDL_SoftWin();
	bool Running();
	void Present();
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Point2u& Size();
	const LDL_Point2u& Pos();
private:
	bool InitMouse();
	bool MousePress(size_t button);
	LDL_BaseWindow _BaseWindow;
	LDL_ErrorHandler* _ErrorHandler;
	LDL_IRenderContext* _Context;
	LDL_Eventer _Eventer;
};

#endif
