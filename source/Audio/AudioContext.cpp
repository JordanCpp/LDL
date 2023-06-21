#include <LDL/Audio/AudioContext.hpp>

#ifdef LDL_AUDIO_DIRECT_SOUND_8
#include "DirectSound8/AudioContextImpl.hpp"
#elif LDL_AUDIO_XAUDIO2
#include "XAudio2/AudioContextImpl.hpp"
#elif LDL_AUDIO_OPENAL
#include "OpenAL/AudioContextImpl.hpp"
#endif

using namespace LDL::Audio;
using namespace LDL::Graphics;

AudioContext::AudioContext(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels) :
	_AudioContextImpl(new AudioContextImpl(window, rate, bits, channels))
{
}

AudioContext::~AudioContext()
{
	delete _AudioContextImpl;
}

AudioContextImpl* AudioContext::GetAudioContextImpl()
{
	return _AudioContextImpl;
}

void* AudioContext::Context()
{
	return NULL;
}