#include <LDL/Audio/Sound.hpp>

#if defined(_WIN32)
#ifdef LDL_AUDIO_DIRECT_SOUND_8
#include "../Platforms/Windows/Audio/DirectSound8/SoundImpl.hpp"
#elif LDL_AUDIO_XAUDIO2
#include "../Platforms/Windows/Audio/XAudio2/SoundImpl.hpp"
#endif
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