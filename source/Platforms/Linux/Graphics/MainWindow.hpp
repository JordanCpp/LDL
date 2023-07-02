#ifndef LDL_Platforms_Windows_Graphics_MainWindow_hpp
#define LDL_Platforms_Windows_Graphics_MainWindow_hpp

#include <LDL/Graphics/Base/BaseWindow.hpp>
#include <LDL/Events/Eventer.hpp>
#include <LDL/Enums/WindowMode.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <LDL/OpenGL/OpenGL1_1.hpp>

#ifdef __cplusplus
extern "C" {
#endif
#define GLX_USE_GL		1
#define GLX_BUFFER_SIZE		2
#define GLX_LEVEL		3
#define GLX_RGBA		4
#define GLX_DOUBLEBUFFER	5
#define GLX_STEREO		6
#define GLX_AUX_BUFFERS		7
#define GLX_RED_SIZE		8
#define GLX_GREEN_SIZE		9
#define GLX_BLUE_SIZE		10
#define GLX_ALPHA_SIZE		11
#define GLX_DEPTH_SIZE		12
#define GLX_STENCIL_SIZE	13
#define GLX_ACCUM_RED_SIZE	14
#define GLX_ACCUM_GREEN_SIZE	15
#define GLX_ACCUM_BLUE_SIZE	16
#define GLX_ACCUM_ALPHA_SIZE	17

typedef XID GLXDrawable;

#define GLX_SAMPLE_BUFFERS              0x186a0 /*100000*/
#define GLX_SAMPLES                     0x186a1 /*100001*/

typedef struct __GLXcontextRec *GLXContext;

extern Bool glXQueryVersion( Display *dpy, int *maj, int *min );
extern XVisualInfo* glXChooseVisual( Display *dpy, int screen,
				     int *attribList );

extern GLXContext glXCreateContext( Display *dpy, XVisualInfo *vis,
				    GLXContext shareList, Bool direct );

extern Bool glXMakeCurrent( Display *dpy, GLXDrawable drawable,
			    GLXContext ctx);

extern void glXSwapBuffers( Display *dpy, GLXDrawable drawable );

#ifdef __cplusplus
}
#endif

namespace LDL
{
	namespace Graphics
	{
		class MainWindow
		{
		public:
			MainWindow(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode);
			~MainWindow();
			bool Running();
			void PollEvents();
			bool GetEvent(LDL::Events::Event& event);
			bool WaitEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Math::Vec2u& Size();
			const Math::Vec2u& Pos();
		private:
		    BaseWindow _BaseWindow;
			size_t ConvertKey(size_t key);
			LDL::Events::Eventer _Eventer;
			Display* _Display;
			int _ScreenId;
			Screen* _Screen;
			Window _Window;
		};
	}
}

#endif   