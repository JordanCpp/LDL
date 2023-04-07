#include <LDL/Core/RuntimeError.hpp>
#include "MixerImpl.hpp"
#include <LDL/Graphics/Window.hpp>
#include "../../Platforms/Windows/Graphics/WindowImpl.hpp"

using namespace LDL::Audio;
using namespace LDL::Core;

MixerImpl::MixerImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels) :
	_Window(window),
	_DirectSound(NULL),
	_DirectPrimaryBuffer(NULL)
{
	HRESULT result;

	result = DirectSoundCreate8(&DSDEVID_DefaultPlayback, &_DirectSound, NULL);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("DirectSoundCreate8 failed");

	result = _DirectSound->SetCooperativeLevel(_Window->GetWindowImpl()->Hwnd(), DSSCL_PRIORITY);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("SetCooperativeLevel failed");

	WAVEFORMATEX format;
	ZeroMemory(&format, sizeof(WAVEFORMATEX));

	format.cbSize          = sizeof(WAVEFORMATEX);
	format.wFormatTag      = WAVE_FORMAT_PCM;
	format.nChannels       = (WORD)channels;
	format.nSamplesPerSec  = (DWORD)rate;
	format.wBitsPerSample  = (WORD)bits;
	format.nBlockAlign     = (format.wBitsPerSample / 8) * format.nChannels;
	format.nAvgBytesPerSec = format.nSamplesPerSec * format.nBlockAlign;

	DSBUFFERDESC buffer;
	ZeroMemory(&buffer, sizeof(DSBUFFERDESC));
	
	buffer.dwSize        = sizeof(DSBUFFERDESC);
	buffer.dwFlags       = DSBCAPS_PRIMARYBUFFER;
	buffer.dwBufferBytes = 0;
	buffer.lpwfxFormat   = 0;

	result = _DirectSound->CreateSoundBuffer(&buffer, &_DirectPrimaryBuffer, 0);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("CreateSoundBuffer failed");

	result = _DirectPrimaryBuffer->SetFormat(&format);
	if (FAILED(result))
		throw LDL::Core::RuntimeError("SetFormat failed");
}

MixerImpl::~MixerImpl()
{
	if (_DirectPrimaryBuffer)
		_DirectPrimaryBuffer->Release();

	if (_DirectSound)
		_DirectSound->Release();
}