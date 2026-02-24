// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Audio/Mixer.hpp>

#if defined(_WIN32)
#include <LDL/Platforms/Windows/Audio/DirectSound8/MixerImpl.hpp>
#elif defined(__unix__)
#include <LDL/Platforms/Linux/Audio/OpenAL/MixerImpl.hpp>
#endif

using namespace LDL;

Mixer::Mixer() :
	_impl(new MixerImpl())
{
}

Mixer::~Mixer()
{
	delete _impl;
}

MixerImpl* Mixer::GetMixerImpl()
{
	return _impl;
}

void Mixer::Play(Sound* sound)
{
	_impl->Play(sound);
}

void Mixer::Stop(Sound* sound)
{
	_impl->Stop(sound);
}
