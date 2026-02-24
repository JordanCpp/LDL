// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Audio_AudioContext_hpp
#define LDL_Audio_AudioContext_hpp

#include <LDL/Graphics/Window.hpp>

namespace LDL
{
	class AudioContextImpl;

	class LDL_LIBRARY AudioContext
	{
	public:
		AudioContext(Window* window, size_t rate, size_t bits, size_t channels);
		~AudioContext();
		AudioContextImpl* GetAudioContextImpl();
		void* Context();
	private:
		AudioContextImpl* _impl;
	};
}

#endif  
