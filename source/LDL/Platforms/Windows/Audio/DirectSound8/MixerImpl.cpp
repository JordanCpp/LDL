#include "MixerImpl.hpp"
#include "SoundImpl.hpp"
#include <LDL/Core/Assert.hpp>

using namespace LDL::Audio;
using namespace LDL::Core;

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
