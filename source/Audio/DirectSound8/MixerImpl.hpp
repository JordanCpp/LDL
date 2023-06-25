#ifndef LDL_Audio_DirectSound8_MixerImpl_hpp
#define LDL_Audio_DirectSound8_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>
#include "../../DirectX/DirectX9.hpp"

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