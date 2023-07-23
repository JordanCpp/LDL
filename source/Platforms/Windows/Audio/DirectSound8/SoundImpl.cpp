#include "SoundImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include "../source/Platforms/Windows/Audio/DirectSound8/AudioContextImpl.hpp"

using namespace LDL::Audio;
using namespace LDL::Core;

SoundImpl::SoundImpl(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes)
{
	AudioContextImpl* impl = audioContext->GetAudioContextImpl();

	WAVEFORMATEX waveFormat;
	ZeroMemory(&waveFormat, sizeof(WAVEFORMATEX));

	waveFormat.wFormatTag      = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec  = (DWORD)impl->Rate();
	waveFormat.wBitsPerSample  = (WORD)impl->Bits();
	waveFormat.nChannels       = (WORD)impl->Channels();
	waveFormat.nBlockAlign     = (waveFormat.wBitsPerSample * waveFormat.nChannels) / 8;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize          = 0;

	DSBUFFERDESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));

	bufferDesc.dwSize          = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags         = DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes   = (DWORD)samples;
	bufferDesc.dwReserved      = 0;
	bufferDesc.lpwfxFormat     = &waveFormat;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer* soundBuffer;

	HRESULT result = impl->_DirectSound->CreateSoundBuffer(&bufferDesc, &soundBuffer, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateSoundBuffer failed");

	result = soundBuffer->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&_SecondaryBuffer);
	if (FAILED(result))
		throw RuntimeError("QueryInterface failed");

	soundBuffer->Release();
	soundBuffer = NULL;

	unsigned char* bufferPtr;
	unsigned long bufferSize;

	result = _SecondaryBuffer->Lock(0, (DWORD)samples, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);
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
