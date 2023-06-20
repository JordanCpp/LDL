#include <LDL/Audio/Sound.hpp>

#ifdef LDL_AUDIO_DIRECT_SOUND_8
#include "DirectSound8/SoundImpl.hpp"
#elif LDL_AUDIO_XAUDIO2
#include "XAudio2/SoundImpl.hpp"
#elif LDL_AUDIO_OPENAL
#include "OpenAL/SoundImpl.hpp"
#endif

using namespace LDL::Audio;

Sound::Sound() :
	_SoundImpl(NULL)
{
}

SoundImpl* Sound::GetSoundImpl()
{
	return _SoundImpl;
}