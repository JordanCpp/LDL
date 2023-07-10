#include <LDL/Audio/Sound.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Audio/DirectSound8/SoundImpl.hpp"
#elif defined(__unix__)
#include "../Platforms/Linux/Audio/OpenAL/SoundImpl.hpp"
#endif

using namespace LDL::Audio;

Sound::Sound(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes) :
	_SoundImpl(new SoundImpl(audioContext, channels, rate, samples, bytes))
{
}

Sound::~Sound()
{
	delete _SoundImpl;
}

SoundImpl* Sound::GetSoundImpl()
{
	return _SoundImpl;
}