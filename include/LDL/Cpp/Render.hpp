#ifndef LDL_Cpp_Render_hpp
#define LDL_Cpp_Render_hpp

#include <LDL/Low/Creators.hpp>
#include <LDL/Cpp/RContext.hpp>
#include <LDL/Cpp/Window.hpp>
#include <LDL/Cpp/Surface.hpp>

class LDL_Render
{
public:
	LDL_Render(LDL_RenderContext* context, LDL_Window* window)
	{
		_Render = RenderCreate(context->GetRenderContext(), window->GetWindow());
	}

	~LDL_Render()
	{
		 Destroy(_Render);
	}

	LDL_IRender* GetRender()
	{
		return _Render;
	}

	void SetColor(const LDL_Color& color)
	{
		_Render->SetColor(color);
	}

	void Clear()
	{
		_Render->Clear();
	}

	void Begin()
	{
		_Render->Begin();
	}

	void End()
	{
		_Render->End();
	}

	void Line(const LDL_Point2u& first, const LDL_Point2u& last)
	{
		_Render->Line(first, last);
	}

	void Fill(const LDL_Point2u& first, const LDL_Point2u& last)
	{
		_Render->Fill(first, last);
	}

	void Draw(LDL_Surface* surface, const LDL_Point2u& pos)
	{
		_Render->Draw(surface->GetSurface(), pos);
	}
private:
	LDL_IRender* _Render;
};

#endif
