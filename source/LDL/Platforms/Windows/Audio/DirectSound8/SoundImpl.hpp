// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Audio_DirectSound8_SoundImpl_hpp
#define LDL_Platforms_Windows_Audio_DirectSound8_SoundImpl_hpp

#include <LDL/Core/Types.hpp>
#include <LDL/Audio/AudioContext.hpp>
#include <LDL/Platforms/Windows/DirectX/DirectSound8.hpp>

namespace LDL
{
	class SoundImpl
	{
	public:
		SoundImpl(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes);
		~SoundImpl();
	public:
		IDirectSoundBuffer8* _secondaryBuffer;
	};
}

#endif    
