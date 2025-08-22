// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Audio/AudioContext.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Audio/DirectSound8/AudioContextImpl.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Audio/OpenAL/AudioContextImpl.hpp>
#endif

using namespace LDL::Audio;
using namespace LDL::Graphics;

AudioContext::AudioContext(Window* window, size_t rate, size_t bits, size_t channels) :
	_impl(new AudioContextImpl(window, rate, bits, channels))
{
}

AudioContext::~AudioContext()
{
	delete _impl;
}

AudioContextImpl* AudioContext::GetAudioContextImpl()
{
	return _impl;
}

void* AudioContext::Context()
{
	return NULL;
}
