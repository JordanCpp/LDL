// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Audio/DirectSound8/MixerImpl.hpp>
#include <LDL/Platforms/Windows/Audio/DirectSound8/SoundImpl.hpp>

using namespace LDL;

MixerImpl::MixerImpl()
{
}

MixerImpl::~MixerImpl()
{
}

void MixerImpl::Play(Sound* sound)
{
	HRESULT result;

	IDirectSoundBuffer8* snd = sound->GetSoundImpl()->_secondaryBuffer;

	result = snd->SetCurrentPosition(0);
	LDL_ASSERT_DETAIL(!FAILED(result), "SetCurrentPosition failed");

	result = snd->SetVolume(DSBVOLUME_MAX);
	LDL_ASSERT_DETAIL(!FAILED(result), "SetVolume failed");

	result = snd->Play(0, 0, 0);
	LDL_ASSERT_DETAIL(!FAILED(result), "QueryInterface failed");
}

void MixerImpl::Stop(Sound* sound)
{
	IDirectSoundBuffer8* snd = sound->GetSoundImpl()->_secondaryBuffer;

	HRESULT result = snd->Stop();
	LDL_ASSERT_DETAIL(!FAILED(result), "Stop failed");
}
