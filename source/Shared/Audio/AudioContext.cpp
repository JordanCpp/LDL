#include <LDL/Audio/AudioContext.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Audio/DirectSound8/AudioContextImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Audio/OpenAL/AudioContextImpl.hpp"
#endif

using namespace LDL::Audio;
using namespace LDL::Graphics;

AudioContext::AudioContext(Window* window, size_t rate, size_t bits, size_t channels) :
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