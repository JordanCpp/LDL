#ifndef LDL_Windows_GdiWin_hpp
#define LDL_Windows_GdiWin_hpp

#include <LDL/Low/Abstract.hpp>
#include "MainWin.hpp"

class LDL_GdiWindow: public LDL_IWindow
{
public:
	LDL_GdiWindow(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
	bool Running();
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Point2u& Size();
	const LDL_Point2u& Pos();
public:
	LDL_MainWinow     _MainWindow;
};

#endif
