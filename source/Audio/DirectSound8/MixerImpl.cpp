#include <LDL/Core/RuntimeError.hpp>
#include "MixerImpl.hpp"
#include "SoundImpl.hpp"

using namespace LDL::Audio;
using namespace LDL::Core;

MixerImpl::MixerImpl()
{
}

MixerImpl::~MixerImpl()
{
}

void MixerImpl::Play(Sound* sound)
{
	HRESULT result;

	SoundImpl* soundImpl = sound->GetSoundImpl();

	result = soundImpl->_SecondaryBuffer->SetCurrentPosition(0);
	if (FAILED(result))
		throw RuntimeError("SetCurrentPosition failed");


	result = soundImpl->_SecondaryBuffer->SetVolume(DSBVOLUME_MAX);
	if (FAILED(result))
		throw RuntimeError("SetVolume failed");


	result = soundImpl->_SecondaryBuffer->Play(0, 0, 0);
	if (FAILED(result))
		throw RuntimeError("QueryInterface failed");
}