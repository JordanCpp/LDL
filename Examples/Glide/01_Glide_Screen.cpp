#include <LDL/Graphics/Window.hpp>
#include <LDL/Graphics/Render.hpp>
#include <LDL/Enums/RenderMode.hpp>
#include <LDL/APIs/Glide/GlideLoader.hpp>

using namespace LDL::Glide;
using namespace LDL::Graphics;
using namespace LDL::Events;
using namespace LDL::Enums;
using namespace LDL::Core;
using namespace LDL::Math;

int main()
{
		GlideLoader glideLoader;
		RenderContext renderContext(RenderMode::Glide);
		Window window(&renderContext, Vec2u(0, 0), Vec2u(800, 600), "01_Glide_Line");

		Event report;

		grGlideInit();
		grSstSelect(0);

		FxBool result = grSstWinOpen((FxU32)window.NativeHandle(), GR_RESOLUTION_800x600, GR_REFRESH_60Hz, GR_COLORFORMAT_RGBA, GR_ORIGIN_UPPER_LEFT, 2, 1);

		if (result)
		{
			grVertexLayout(GR_PARAM_XY, 0, GR_PARAM_ENABLE);
			grColorCombine(GR_COMBINE_FUNCTION_LOCAL, GR_COMBINE_FACTOR_NONE, GR_COMBINE_LOCAL_CONSTANT, GR_COMBINE_OTHER_NONE, FXFALSE);

			Color screenColor(34, 177, 76);

			while (window.Running())
			{
				grBufferClear(screenColor.toInt(), 0, 0);

				while (window.GetEvent(report))
				{
					if (report.Type == IsQuit)
					{
						window.StopEvent();
					}
				}

				grBufferSwap(1);

				window.PollEvents();
			}

			grGlideShutdown();
		}

	return 0;
}
