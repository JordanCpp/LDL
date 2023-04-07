#include <LDL/Audio/Mixer.hpp>

#ifdef LDL_AUDIO_DIRECT_SOUND_8
#include "DirectSound8/MixerImpl.hpp"
#elif LDL_AUDIO_XAUDIO2
#include "XAudio2/MixerImpl.hpp"
#elif LDL_AUDIO_OPENAL
#include "OpenAL/MixerImpl.hpp"
#endif

using namespace LDL::Audio;
using namespace LDL::Graphics;

Mixer::Mixer(Window* window, size_t rate, size_t bits, size_t channels) :
	_MixerImpl(new MixerImpl(window, rate, bits, channels))
{
}

MixerImpl* Mixer::GetMixerImpl()
{
	return _MixerImpl;
}