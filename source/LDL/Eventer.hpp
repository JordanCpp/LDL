// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Events_Eventer_hpp
#define LDL_Events_Eventer_hpp

#include <LDL/Event.hpp>
#include <LDL/RingBuffer.hpp>

class LDL_LIBRARY LDL_Eventer
{
public:
	enum
	{
		Max = 128
	};
	LDL_Eventer();
	bool Empty();
	void Push(LDL_Event& event);
	bool Pop(LDL_Event& event);
	bool Running();
	void Stop();
private:
	bool                       _running;
	LDL_RingBuffer<LDL_Event, Max> _queue;
};

#endif
