#include "SoundImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../source/Audio/DirectSound8/AudioContextImpl.hpp"

using namespace LDL::Audio;
using namespace LDL::Core;

SoundImpl::SoundImpl(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes)
{
	WAVEFORMATEX waveFormat;
	ZeroMemory(&waveFormat, sizeof(WAVEFORMATEX));

	waveFormat.wFormatTag      = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec  = audioContext->GetAudioContextImpl()->Rate();
	waveFormat.wBitsPerSample  = audioContext->GetAudioContextImpl()->Bits();
	waveFormat.nChannels       = audioContext->GetAudioContextImpl()->Channels();
	waveFormat.nBlockAlign     = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize          = 0;


	DSBUFFERDESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));

	bufferDesc.dwSize = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags = DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes = samples;
	bufferDesc.dwReserved = 0;
	bufferDesc.lpwfxFormat = &waveFormat;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer* soundBuffer;

	HRESULT result = audioContext->GetAudioContextImpl()->_DirectSound->CreateSoundBuffer(&bufferDesc, &soundBuffer, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateSoundBuffer failed");

	result = soundBuffer->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&_SecondaryBuffer);
	if (FAILED(result))
		throw RuntimeError("QueryInterface failed");

	soundBuffer->Release();
	soundBuffer = NULL;

	unsigned char* bufferPtr;
	unsigned long bufferSize;

	result = _SecondaryBuffer->Lock(0, samples, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);
	if (FAILED(result))
		throw RuntimeError("Lock failed");

	memcpy(bufferPtr, bytes, samples);

	result = _SecondaryBuffer->Unlock(bufferPtr, bufferSize, NULL, 0);
	if (FAILED(result))
		throw RuntimeError("Unlock failed");
}

SoundImpl::~SoundImpl()
{
	if (_SecondaryBuffer)
	{
		_SecondaryBuffer->Release();
		_SecondaryBuffer = NULL;
	}
}