#ifndef LDL_Events_Eventer_hpp
#define LDL_Events_Eventer_hpp

#include <LDL/Events/Event.hpp>
#include <queue>

namespace LDL
{
	namespace Events
	{
		class LDL_LIBRARY Eventer
		{
		public:
			Eventer();
			bool Empty();
			void Push(Event& event);
			bool Pop(Event& event);
			bool Running();
			void Stop();
		private:
			bool _running;
			std::queue<Event> _queue;
		};
	}
}

#endif
