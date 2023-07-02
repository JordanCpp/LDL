#ifndef LDL_Platforms_Linux_Audio_OpenAL_AudioContextImpl_hpp
#define LDL_Platforms_Linux_Audio_OpenAL_AudioContextImpl_hpp

#include <LDL/Audio/AudioContext.hpp>

namespace LDL
{
	namespace Audio
	{
		class AudioContextImpl
		{
		public:
			AudioContextImpl(LDL::Graphics::Window* window, size_t rate, size_t bits, size_t channels);
			~AudioContextImpl();
			size_t Rate();
			size_t Bits();
			size_t Channels();
		private:
			size_t _Rate;
			size_t _Bits; 
			size_t _Channels;
		};
	}
}

#endif    