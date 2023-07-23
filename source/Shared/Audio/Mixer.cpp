#include <LDL/Audio/Mixer.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Audio/DirectSound8/MixerImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Audio/OpenAL/MixerImpl.hpp"
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

void Mixer::Stop(Sound* sound)
{
	_MixerImpl->Stop(sound);
}
