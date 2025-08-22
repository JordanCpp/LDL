// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#ifndef LDL_Audio_Mixer_hpp
#define LDL_Audio_Mixer_hpp

#include <LDL/Audio/Sound.hpp>

namespace LDL
{
	namespace Audio
	{
		class MixerImpl;

		class LDL_LIBRARY Mixer
		{
		public:
			Mixer();
			~Mixer();
			MixerImpl* GetMixerImpl();
			void Play(Sound* sound);
			void Stop(Sound* sound);
		private:
			MixerImpl* _impl;
		};
	}
}

#endif   
