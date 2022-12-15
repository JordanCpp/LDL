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
			void Push(Event& event);
			bool Pop(Event& event);
			bool Running();
			void Stop();
		private:
			bool _Running;
			std::queue<Event> _Queue;
		};
	}
}

#endif