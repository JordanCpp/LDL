#ifndef LDL_Audio_Sound_hpp
#define LDL_Audio_Sound_hpp

#include <LDL/Audio/AudioContext.hpp>

namespace LDL
{
	namespace Audio
	{
		class SoundImpl;

		class LDL_LIBRARY Sound
		{
		public:
			Sound(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes);
			~Sound();
			SoundImpl* GetSoundImpl();
		private:
			SoundImpl* _impl;
		};
	}
}

#endif  
