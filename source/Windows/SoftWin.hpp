#ifndef LDL_Windows_SoftWin_hpp
#define LDL_Windows_SoftWin_hpp

#include <LDL/Low/Abstract.hpp>
#include "MainWin.hpp"

class LDL_SoftWindow: public LDL_IWindow
{
public:
	LDL_SoftWindow(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
	bool Running();
	void Present(LDL_ISurface* surface);
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Point2u& Size();
	const LDL_Point2u& Pos();
private:
	LDL_MainWinow     _MainWindow;
	BITMAPINFO        _BITMAPINFO;
};

#endif
