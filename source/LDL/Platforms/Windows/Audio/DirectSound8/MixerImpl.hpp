// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Platforms_Windows_Audio_DirectSound8_MixerImpl_hpp
#define LDL_Platforms_Windows_Audio_DirectSound8_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>
#include <LDL/Platforms/Windows/DirectX/DirectSound8.hpp>

namespace LDL
{
	class MixerImpl
	{
	public:
		MixerImpl();
		~MixerImpl();
		void Play(Sound* sound);
		void Stop(Sound* sound);
	private:
	};
}

#endif    
