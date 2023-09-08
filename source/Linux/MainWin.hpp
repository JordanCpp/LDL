#ifndef LDL_MainWin_hpp
#define LDL_MainWin_hpp

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
	LDL_BaseWindow _BaseWindow;
	LDL_ErrorHandler* _ErrorHandler;
	LDL_Eventer _Eventer;
};

#endif
