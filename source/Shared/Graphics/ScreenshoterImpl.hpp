#ifndef LDL_Graphics_ScreenshoterImpl_hpp
#define LDL_Graphics_ScreenshoterImpl_hpp

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImpl
		{
		public:
			virtual ~ScreenshoterImpl() {};
			virtual void Shot() = 0;
		private:
		};
	}
}

#endif    