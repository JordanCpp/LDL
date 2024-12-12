#include <LDL/Audio/Mixer.hpp>

#if defined(_WIN32)
#include "../source/Platforms/Windows/Audio/DirectSound8/MixerImpl.hpp"
#elif defined(__unix__)
#include "../source/Platforms/Linux/Audio/OpenAL/MixerImpl.hpp"
#endif

using namespace LDL::Audio;

Mixer::Mixer() :
	_impl(new MixerImpl())
{
}

Mixer::~Mixer()
{
	delete _impl;
}

MixerImpl* Mixer::GetMixerImpl()
{
	return _impl;
}

void Mixer::Play(Sound* sound)
{
	_impl->Play(sound);
}

void Mixer::Stop(Sound* sound)
{
	_impl->Stop(sound);
}
