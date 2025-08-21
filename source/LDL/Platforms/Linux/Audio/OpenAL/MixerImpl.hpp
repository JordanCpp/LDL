#ifndef LDL_Platforms_Linux_Audio_OpenAL_MixerImpl_hpp
#define LDL_Platforms_Linux_Audio_OpenAL_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>

namespace LDL
{
	namespace Audio
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
}

#endif    
