#include "AudioContextImpl.hpp"
#include <LDL/Core/RuntimeError.hpp>
#include <LDL/Graphics/Window.hpp>
#include <LDL/Core/Library.hpp>
#include "../source/Platforms/Windows/Graphics/WindowImpl.hpp"

using namespace LDL::Audio;
using namespace LDL::Core;
using namespace LDL::Graphics;

AudioContextImpl::AudioContextImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels) :
	_Rate(rate),
	_Bits(bits),
	_Channels(channels),
	_DirectSound(NULL),
	_PrimaryBuffer(NULL)
{
	Library library("dsound.dll");

	DirectSoundCreate8 = (PFNDirectSoundCreate8)library.Function("DirectSoundCreate8");

	HRESULT result = DirectSoundCreate8(NULL, &_DirectSound, NULL);

	result = DirectSoundCreate8(NULL, &_DirectSound, NULL);
	if (FAILED(result))
		throw RuntimeError("DirectSoundCreate8 failed");

	result = _DirectSound->SetCooperativeLevel(window->GetWindowImpl()->Hwnd(), DSSCL_PRIORITY);
	if (FAILED(result))
		throw RuntimeError("SetCooperativeLevel failed");

	DSBUFFERDESC bufferDesc;
	ZeroMemory(&bufferDesc, sizeof(DSBUFFERDESC));

	bufferDesc.dwSize          = sizeof(DSBUFFERDESC);
	bufferDesc.dwFlags         = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	bufferDesc.dwBufferBytes   = 0;
	bufferDesc.dwReserved      = 0;
	bufferDesc.lpwfxFormat     = NULL;
	bufferDesc.guid3DAlgorithm = GUID_NULL;

	result = _DirectSound->CreateSoundBuffer(&bufferDesc, &_PrimaryBuffer, NULL);
	if (FAILED(result))
		throw RuntimeError("CreateSoundBuffer failed");

	WAVEFORMATEX waveFormat;
	ZeroMemory(&waveFormat, sizeof(WAVEFORMATEX));

	waveFormat.cbSize          = 0;
	waveFormat.wFormatTag      = WAVE_FORMAT_PCM;
	waveFormat.nChannels       = (WORD)_Channels;
	waveFormat.nSamplesPerSec  = (DWORD)_Rate;
	waveFormat.wBitsPerSample  = (WORD)_Bits;
	waveFormat.nBlockAlign     = (waveFormat.wBitsPerSample / 8) * waveFormat.nChannels;
	waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;

	result = _PrimaryBuffer->SetFormat(&waveFormat);
	if (FAILED(result))
		throw RuntimeError("SetFormat failed");
}

AudioContextImpl::~AudioContextImpl()
{
	if (_PrimaryBuffer)
	{
		_PrimaryBuffer->Release();
		_PrimaryBuffer = NULL;
	}

	if (_DirectSound)
	{
		_DirectSound->Release();
		_DirectSound = NULL;
	}
}

size_t AudioContextImpl::Rate()
{
	return _Rate;
}

size_t AudioContextImpl::Bits()
{
	return _Bits;
}

size_t AudioContextImpl::Channels()
{
	return _Channels;
}