// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

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
