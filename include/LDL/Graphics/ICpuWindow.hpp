#ifndef LDL_Graphics_ICpuWindow_hpp
#define LDL_Graphics_ICpuWindow_hpp

#include <string>
#include <LDL/Graphics/Primitives/Point2u.hpp>
#include <LDL/Events/Event.hpp>

namespace LDL
{
	namespace Graphics
	{
		class ICpuWindow
		{
		public:
			virtual	void Present(uint8_t* pixels) = 0;
			virtual	bool GetEvent(LDL::Events::Event& event) = 0;
			virtual	void StopEvent() = 0;
			virtual	void Title(const std::string& title) = 0;
			virtual	const std::string& Title() = 0;
			virtual	const LDL::Graphics::Point2u& Size() = 0;
			virtual	const LDL::Graphics::Point2u& Pos() = 0;
			virtual ~ICpuWindow() {};
		};
	}
}

#endif    