#ifndef LDL_Platforms_Windows_Graphics_WindowImpl_hpp
#define LDL_Platforms_Windows_Graphics_WindowImpl_hpp

#include <LDL/Events/Event.hpp>
#include <LDL/Math/Vec2.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class WindowImpl
		{
		public:
			virtual ~WindowImpl() {};
			virtual bool Running() = 0;
			virtual void Present() = 0;
			virtual void PollEvents() = 0;
			virtual bool GetEvent(LDL::Events::Event& event) = 0;
			virtual bool WaitEvent(LDL::Events::Event& event) = 0;
			virtual void StopEvent() = 0;
			virtual void Title(const std::string& title) = 0;
			virtual const std::string& Title() = 0;
			virtual const Math::Vec2u& Size() = 0;
			virtual const Math::Vec2u& Pos() = 0;
		private:
		};
	}
}

#endif   