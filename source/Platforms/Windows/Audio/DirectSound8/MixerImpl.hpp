#ifndef LDL_Platforms_Windows_Audio_DirectSound8_MixerImpl_hpp
#define LDL_Platforms_Windows_Audio_DirectSound8_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>
#include "../source/Platforms/Windows/DirectX/DirectX9.hpp"

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
