#ifndef LDL_Platforms_Linux_Audio_OpenAL_SoundImpl_hpp
#define LDL_Platforms_Linux_Audio_OpenAL_SoundImpl_hpp

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
		};
	}
}

#endif    
