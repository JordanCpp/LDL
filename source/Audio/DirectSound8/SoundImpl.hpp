#ifndef LDL_Audio_DirectSound8_SoundImpl_hpp
#define LDL_Audio_DirectSound8_SoundImpl_hpp

#include <dsound.h>
#include <LDL/Core/Types.hpp>
#include <LDL/Audio/AudioContext.hpp>

namespace LDL
{
	namespace Audio
	{
		class SoundImpl
		{
		public:
			SoundImpl(AudioContext* audioContext, size_t channels, size_t rate, size_t samples, uint8_t* bytes);
			~SoundImpl();
		public:
			IDirectSoundBuffer8* _SecondaryBuffer;
		};
	}
}

#endif    