#include <LDL/Audio/Mixer.hpp>

#ifdef LDL_AUDIO_DIRECT_SOUND_8
#include "DirectSound8/MixerImpl.hpp"
#elif LDL_AUDIO_XAUDIO2
#include "XAudio2/MixerImpl.hpp"
#elif LDL_AUDIO_OPENAL
#include "OpenAL/MixerImpl.hpp"
#endif

using namespace LDL::Audio;

Mixer::Mixer() :
	_MixerImpl(new MixerImpl())
{
}

Mixer::~Mixer()
{
	delete _MixerImpl;
}

MixerImpl* Mixer::GetMixerImpl()
{
	return _MixerImpl;
}

void Mixer::Play(Sound* sound)
{
	_MixerImpl->Play(sound);
}