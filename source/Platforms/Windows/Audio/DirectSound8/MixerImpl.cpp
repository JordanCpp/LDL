#include <LDL/Core/RuntimeError.hpp>
#include "MixerImpl.hpp"
#include "SoundImpl.hpp"

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

	IDirectSoundBuffer8* snd = sound->GetSoundImpl()->_SecondaryBuffer;

	result = snd->SetCurrentPosition(0);
	if (FAILED(result))
		throw RuntimeError("SetCurrentPosition failed");


	result = snd->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
		throw RuntimeError("SetVolume failed");


	result = snd->Play(0, 0, 0);
	if (FAILED(result))
		throw RuntimeError("QueryInterface failed");
}

void MixerImpl::Stop(Sound* sound)
{
	IDirectSoundBuffer8* snd = sound->GetSoundImpl()->_SecondaryBuffer;

	HRESULT result = snd->Stop();

	if (FAILED(result))
		throw RuntimeError("Stop failed");
}
