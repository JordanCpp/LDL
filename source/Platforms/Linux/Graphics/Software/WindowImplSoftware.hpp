#ifndef LDL_Platforms_Linux_Graphics_Software_WindowImpl_hpp
#define LDL_Platforms_Linux_Graphics_Software_WindowImpl_hpp

#include "../MainWindow.hpp"
#include "../WindowImpl.hpp"

namespace LDL
{
	namespace Graphics
	{
		class WindowImplSoftware : public WindowImpl
		{
		public:
			WindowImplSoftware(const Math::Vec2u& pos, const Math::Vec2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~WindowImplSoftware();
			void Present(uint8_t* pixels, uint8_t bytesPerPixel);
			void Present();
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
		    MainWindow _Window;
		};
	}
}

#endif 
