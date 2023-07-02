#ifndef LDL_Audio_XAudio2_MixerImpl_hpp
#define LDL_Audio_XAudio2_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>
#include <XAudio2.h>

namespace LDL
{
	namespace Audio
	{
		class MixerImpl
		{
		public:
			MixerImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels);
			~MixerImpl();
		private:
			LDL::Graphics::Window* _Window;
			IXAudio2* _XAudio2;
			IXAudio2MasteringVoice* _XAudio2MasteringVoice;
		};
	}
}

#endif    