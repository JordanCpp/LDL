#ifndef LDL_Cpp_Window_hpp
#define LDL_Cpp_Window_hpp

#include <LDL/Low/Creators.hpp>
#include <LDL/Cpp/RContext.hpp>

class LDL_Window
{
public:
	LDL_Window(LDL_ErrorHandler* errorHandler, LDL_RenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title)
	{
		_Window = WindowCreate(errorHandler, context->GetRenderContext(), pos, size, title);
	}

	~LDL_Window()
	{
		Destroy(_Window);
	}

	LDL_IWindow* GetWindow()
	{
		return _Window;
	}
	bool Running()
	{
		return _Window->Running();
	}

	void PollEvents()
	{
		_Window->PollEvents();
	}

	bool GetEvent(LDL_Event& event)
	{
		return _Window->GetEvent(event);
	}

	bool WaitEvent(LDL_Event& event)
	{
		return _Window->WaitEvent(event);
	}

	const LDL_Point2u& Size()
	{
		return _Window->Size();
	}

	void StopEvent()
	{
		_Window->StopEvent();
	}
private:
	LDL_IWindow* _Window;
};

#endif
