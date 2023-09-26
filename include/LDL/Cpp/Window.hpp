#ifndef LDL_Cpp_Window_hpp
#define LDL_Cpp_Window_hpp

#include <LDL/Low/Creators.hpp>
#include <LDL/Cpp/RContext.hpp>
#include <LDL/Low/Enums.hpp>

class LDL_Window
{
public:
	LDL_Window(LDL_RenderContext* context, const LDL_Point2u& pos, const LDL_Point2u& size, const char* title, size_t mode = LDL_WindowMode::Resized)
	{
		_Window = LDL_WindowCreate(context->GetRenderContext(), pos, size, title, mode);
	}

	~LDL_Window()
	{
		LDL_Destroy(_Window);
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

	void Title(const char* title)
	{
		_Window->Title(title);
	}
private:
	LDL_IWindow* _Window;
};

#endif
