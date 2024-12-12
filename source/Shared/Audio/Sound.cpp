#include <LDL/Audio/Sound.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Audio/DirectSound8/SoundImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Audio/OpenAL/SoundImpl.hpp"
#endif

using namespace LDL::Audio;

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
