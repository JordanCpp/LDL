#ifndef LDL_Audio_DirectSound8_MixerImpl_hpp
#define LDL_Audio_DirectSound8_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>
#include <dsound.h>

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
		private:
		};
	}
}

#endif    