#ifndef LDL_Graphics_ScreenShotterImpl_hpp
#define LDL_Graphics_ScreenShotterImpl_hpp

namespace LDL
{
	namespace Graphics
	{
		class ScreenShotterImpl
		{
		public:
			virtual ~ScreenShotterImpl() {};
			virtual void Shot() = 0;
		private:
		};
	}
}

#endif    
