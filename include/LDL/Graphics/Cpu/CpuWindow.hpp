#ifndef LDL_Graphics_CpuWindow_hpp
#define LDL_Graphics_CpuWindow_hpp

#include <string>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Events/Event.hpp>
#include <LDL/Enums/WindowMode.hpp>
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class CpuWindowImpl;

		class CpuWindow : public LDL::Core::FastPimpl
		{
		public:
			CpuWindow(const Point2u& pos, const Point2u& size, const std::string& title, size_t mode = LDL::Enums::WindowMode::Resized);
			~CpuWindow();
			void Present(uint8_t* pixels);
			bool GetEvent(LDL::Events::Event& event);
			void StopEvent();
			void Title(const std::string& title);
			const std::string& Title();
			const Point2u& Size();
			const Point2u& Pos();
		private:
			CpuWindowImpl* _CpuWindowImpl;
		};
	}
}

#endif    