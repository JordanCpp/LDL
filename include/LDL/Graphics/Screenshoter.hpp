#ifndef LDL_Graphics_Screenshoter_hpp
#define LDL_Graphics_Screenshoter_hpp

#include <LDL/Graphics/Render.hpp>

namespace LDL
{
	namespace Graphics
	{
		class ScreenshoterImpl;

		class Screenshoter : public LDL::Core::FastPimpl
		{
		public:
			Screenshoter(const std::string& path, const std::string& name, Render* render, Surface* image);
			~Screenshoter();
			void Shot();
		private:
			ScreenshoterImpl* _ScreenshoterImpl;
		};
	}
}

#endif  