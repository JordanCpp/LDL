#include <LDL/Audio/Mixer.hpp>

#ifdef LDL_AUDIO_DIRECT_SOUND_8
#include "../Audio/DirectSound8/MixerImpl.hpp"
#endif

using namespace LDL::Audio;

Mixer::Mixer(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels) :
	_MixerImpl(new MixerImpl(window, rate, bits, channels))
{
}

MixerImpl* Mixer::GetMixerImpl()
{
	return _MixerImpl;
}