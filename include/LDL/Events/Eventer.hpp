#ifndef LDL_Events_Eventer_hpp
#define LDL_Events_Eventer_hpp

#include <LDL/Events/Event.hpp>
#include <queue>

namespace LDL
{
	namespace Events
	{
		class Eventer
		{
		public:
			Eventer();
			void Push(LDL::Events::Event& event);
			bool Pop(LDL::Events::Event& event);
			bool Running();
			void Stop();
		private:
			bool _Running;
			std::queue<LDL::Events::Event> _Queue;
		};
	}
}

#endif