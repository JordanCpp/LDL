#ifndef LDL_Renders_GL1Rend_hpp
#define LDL_Renders_GL1Rend_hpp

#include "../WinGL/GL1Win.hpp"
#include <LDL/Low/Mat4f.hpp>

class LDL_GL1Render : public LDL_IRender
{
public:
	LDL_GL1Render(LDL_IRenderContext* context, LDL_IWindow* window);
	~LDL_GL1Render();
	void SetColor(const LDL_Color& color);
	void Line(const LDL_Point2u& first, const LDL_Point2u& last);
	void Fill(const LDL_Point2u& pos, const LDL_Point2u& size);
	void Clear();
	void Begin();
	void End();
	void Draw(LDL_ISurface* surface, const LDL_Point2u& pos);
private:
	LDL_IRenderContext* _RenderContext;
	LDL_IWindow* _Window;
	LDL_Color _Color;
	LDL_Mat4f _Projection;
	LDL_Mat4f _ModelView;
};

#endif
