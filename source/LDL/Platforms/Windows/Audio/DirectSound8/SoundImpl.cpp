// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Platforms/Windows/Audio/DirectSound8/SoundImpl.hpp>
#include <LDL/Platforms/Windows/Audio/DirectSound8/AudioContextImpl.hpp>

using namespace LDL;

SoundImpl::SoundImpl(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes)
{
	AudioContextImpl* impl = audioContext->GetAudioContextImpl();

	WAVEFORMATEX waveFormat;
	LDL_memset(&waveFormat, 0, sizeof(WAVEFORMATEX));

	waveFormat.wFormatTag      = WAVE_FORMAT_PCM;
	waveFormat.nSamplesPerSec  = (DWORD)impl->Rate();
	waveFormat.wBitsPerSample  = (WORD)impl->Bits();
	waveFormat.nChannels       = (WORD)impl->Channels();
	waveFormat.nBlockAlign     = (waveFormat.wBitsPerSample * waveFormat.nChannels) / 8;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;
	waveFormat.cbSize          = 0;

	DSBUFFERDESC bufferDesc;
	LDL_memset(&bufferDesc, 0, sizeof(DSBUFFERDESC));

	bufferDesc.dwSize          = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags         = DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes   = (DWORD)samples;
	bufferDesc.dwReserved      = 0;
	bufferDesc.lpwfxFormat     = &waveFormat;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer* soundBuffer;

	HRESULT result = impl->_directSound->CreateSoundBuffer(&bufferDesc, &soundBuffer, NULL);
	LDL_ASSERT_DETAIL(!FAILED(result), "CreateSoundBuffer failed");

	result = soundBuffer->QueryInterface(IID_IDirectSoundBuffer8, (LPVOID*)&_secondaryBuffer);
	LDL_ASSERT_DETAIL(!FAILED(result), "QueryInterface failed");

	soundBuffer->Release();
	soundBuffer = NULL;

	unsigned char* bufferPtr;
	unsigned long bufferSize;

	result = _secondaryBuffer->Lock(0, (DWORD)samples, (void**)&bufferPtr, (DWORD*)&bufferSize, NULL, 0, 0);
	LDL_ASSERT_DETAIL(!FAILED(result), "Lock failed");

	LDL_memcpy(bufferPtr, bytes, samples);

	result = _secondaryBuffer->Unlock(bufferPtr, bufferSize, NULL, 0);
	LDL_ASSERT_DETAIL(!FAILED(result), "Unlock failed");
}

SoundImpl::~SoundImpl()
{
	if (_secondaryBuffer)
	{
		_secondaryBuffer->Release();
		_secondaryBuffer = NULL;
	}
}
