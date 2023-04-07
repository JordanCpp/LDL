#ifndef LDL_Audio_OpenAL_MixerImpl_hpp
#define LDL_Audio_OpenAL_MixerImpl_hpp

#include <LDL/Audio/Mixer.hpp>

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
		};
	}
}

#endif    