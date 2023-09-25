#ifndef LDL_Windows_GL1Window_hpp
#define LDL_Windows_GL1Window_hpp

#include "../Windows/MainWin.hpp"
#include <LDL/OpenGL/OpenGLLoader.hpp>

class LDL_GL1Window : public LDL_IWindow
{
public:
	LDL_GL1Window(const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode);
	~LDL_GL1Window();
	bool Present();
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
	bool InitDC();
	bool InitPixelFormat();
	bool InitContext();
	bool InitOpenGL();
	HGLRC _HGLRC;
	LDL_MainWinow _MainWindow;
	LDL_OpenGLLoader _OpenGLLoader;
};

#endif
