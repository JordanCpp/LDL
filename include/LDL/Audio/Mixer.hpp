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
