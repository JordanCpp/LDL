// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Core/Assert.hpp>
#include <LDL/Core/Library.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Shared/Graphics/Impls/WindowImpl.hpp>
#include <LDL/Platforms/Windows/Audio/DirectSound8/AudioContextImpl.hpp>

using namespace LDL;

AudioContextImpl::AudioContextImpl(Window* window, size_t rate, size_t bits, size_t channels) :
	_rate(rate),
	_bits(bits),
	_channels(channels),
	_directSound(NULL),
	_primaryBuffer(NULL)
{
	Library library("dsound.dll");

	DirectSoundCreate8 = (PFNDirectSoundCreate8)library.Function("DirectSoundCreate8");

	HRESULT result = DirectSoundCreate8(NULL, &_directSound, NULL);

	result = DirectSoundCreate8(NULL, &_directSound, NULL);
	LDL_ASSERT_DETAIL(!FAILED(result), "DirectSoundCreate8 failed");

	result = _directSound->SetCooperativeLevel((HWND)window->GetWindowImpl()->NativeHandle(), DSSCL_PRIORITY);
	LDL_ASSERT_DETAIL(!FAILED(result), "SetCooperativeLevel failed");

	DSBUFFERDESC bufferDesc;
	memset(&bufferDesc, 0, sizeof(DSBUFFERDESC));

	bufferDesc.dwSize          = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags         = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes   = 0;
	bufferDesc.dwReserved      = 0;
	bufferDesc.lpwfxFormat     = NULL;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	result = _directSound->CreateSoundBuffer(&bufferDesc, &_primaryBuffer, NULL);
	LDL_ASSERT_DETAIL(!FAILED(result), "CreateSoundBuffer failed");

	WAVEFORMATEX waveFormat;
	memset(&waveFormat, 0, sizeof(WAVEFORMATEX));

	waveFormat.cbSize          = 0;
	waveFormat.wFormatTag      = WAVE_FORMAT_PCM;
	waveFormat.nChannels       = (WORD)_channels;
	waveFormat.nSamplesPerSec  = (DWORD)_rate;
	waveFormat.wBitsPerSample  = (WORD)_bits;
	waveFormat.nBlockAlign     = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;

	result = _primaryBuffer->SetFormat(&waveFormat);
	LDL_ASSERT_DETAIL(!FAILED(result), "SetFormat failed");
}

AudioContextImpl::~AudioContextImpl()
{
	if (_primaryBuffer)
	{
		_primaryBuffer->Release();
		_primaryBuffer = NULL;
	}

	if (_directSound)
	{
		_directSound->Release();
		_directSound = NULL;
	}
}

size_t AudioContextImpl::Rate()
{
	return _rate;
}

size_t AudioContextImpl::Bits()
{
	return _bits;
}

size_t AudioContextImpl::Channels()
{
	return _channels;
}
