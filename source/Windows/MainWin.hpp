#ifndef LDL_Windows_MainWin_hpp
#define LDL_Windows_MainWin_hpp

#include "WinX.hpp"
#include <LDL/Low/Point2u.hpp>
#include <LDL/Low/Eventer.hpp>
#include <LDL/Low/EHandler.hpp>
#include <LDL/Low/BaseWin.hpp>

class LDL_MainWinow
{
public:
	LDL_MainWinow(LDL_ErrorHandler * errorHandler, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
	~LDL_MainWinow();
	bool Running();
	void PollEvents();
	bool GetEvent(LDL_Event& event);
	bool WaitEvent(LDL_Event& event);
	void StopEvent();
	void Title(const char* title);
	const char* Title();
	const LDL_Point2u& Size();
	const LDL_Point2u& Pos();
private:
	void ClearStruct();
	bool InitHinstance();
	bool InitWndClass();
	bool InitHwnd(size_t mode);
	bool InitPointer();
	bool InitHdc();
	size_t ConvertKey(size_t key);
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK Handler(UINT message, WPARAM wParam, LPARAM lParam);
	LDL_BaseWindow _BaseWindow;
	LDL_ErrorHandler* _ErrorHandler;
	LDL_Eventer _Eventer;
	WNDCLASS  _WNDCLASS;
	HINSTANCE _HINSTANCE;
	MSG       _MSG;
	ATOM      _ATOM;
public:
	HWND _HWND;
	HDC  _HDC;
};

#endif
