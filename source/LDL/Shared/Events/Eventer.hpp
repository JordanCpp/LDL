#ifndef LDL_Events_Eventer_hpp
#define LDL_Events_Eventer_hpp

#include <LDL/Containers/RingBuffer.hpp>
#include <LDL/Events/Event.hpp>

namespace LDL
{
	namespace Events
	{
		class LDL_LIBRARY Eventer
		{
		public:
			enum
			{
				Max = 1024
			};
			Eventer();
			bool Empty();
			void Push(Event& event);
			bool Pop(Event& event);
			bool Running();
			void Stop();
		private:
			bool                   _running;
			RingBuffer<Event, Max> _queue;
		};
	}
}

#endif
