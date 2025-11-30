// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Eventer_hpp
#define LDL_Eventer_hpp

#include <LDL/Events.hpp>
#include <LDL/RingBuf.hpp>

class LDL_LIBRARY LDL_Eventer
{
public:
	enum
	{
		MaxEvents = 128
	};
	LDL_Eventer();
	bool Empty() const;
	void Push(LDL_Event& event);
	bool Pop(LDL_Event& event);
	bool Running() const;
	void Stop();
private:
	bool                      _running;
	LDL_RingBuffer<LDL_Event> _queue;
};

#endif
