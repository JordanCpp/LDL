#ifndef LDL_Platforms_Windows_Graphics_CpuWindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_CpuWindowImpl_hpp

#include "../MainWindow.hpp"

namespace LDL
{
	namespace Graphics
	{
		class CpuWindowImpl
		{
		public:
			CpuWindowImpl(const LDL::Graphics::Point2u& pos, const LDL::Graphics::Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~CpuWindowImpl();
			void Present(uint8_t* pixels);
			bool GetEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const LDL::Graphics::Point2u& Size();
			const LDL::Graphics::Point2u& Pos();
		private:
			LDL::Graphics::Windows::MainWindow _Window;
			BITMAPINFO _BITMAPINFO;
		};
	}
}

#endif    