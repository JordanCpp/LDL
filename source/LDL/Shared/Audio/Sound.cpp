// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Audio/Sound.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Audio/DirectSound8/SoundImpl.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Audio/OpenAL/SoundImpl.hpp>
#endif

using namespace LDL;

Sound::Sound(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes) :
	_impl(new SoundImpl(audioContext, channels, rate, samples, bytes))
{
}

Sound::~Sound()
{
	delete _impl;
}

SoundImpl* Sound::GetSoundImpl()
{
	return _impl;
}
