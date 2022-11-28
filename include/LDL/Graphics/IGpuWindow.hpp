#ifndef LDL_Graphics_IGpuWindow_hpp
#define LDL_Graphics_IGpuWindow_hpp

#include <string>
#include <LDL/Events/Event.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
	namespace Graphics
	{
		class IGpuWindow
		{
		public:
			virtual	void Present() = 0;
			virtual	bool GetEvent(LDL::Events::Event& event) = 0;
			virtual	bool WaitEvent(LDL::Events::Event& event) = 0;
			virtual	void StopEvent() = 0;
			virtual	void Title(const std::string& title) = 0;
			virtual	const std::string& Title() = 0;
			virtual	const LDL::Graphics::Point2u& Size() = 0;
			virtual	const LDL::Graphics::Point2u& Pos() = 0;
			virtual ~IGpuWindow() {};
		};
	}
}

#endif 