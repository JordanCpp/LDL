// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Audio_DirectSound8_AudioContextImpl_hpp
#define LDL_Platforms_Windows_Audio_DirectSound8_AudioContextImpl_hpp

#include <LDL/Audio/AudioContext.hpp>
#include <LDL/Platforms/Windows/DirectX/DirectSound8.hpp>

namespace LDL
{
	class AudioContextImpl
	{
	public:
		AudioContextImpl(LDL::Window* window, size_t rate, size_t bits, size_t channels);
		~AudioContextImpl();
		size_t Rate();
		size_t Bits();
		size_t Channels();
	private:
		size_t _rate;
		size_t _bits;
		size_t _channels;
	public:
		IDirectSound8*      _directSound;
		IDirectSoundBuffer* _primaryBuffer;
	};
}

#endif  
