#ifndef LDL_Audio_Sound_hpp
#define LDL_Audio_Sound_hpp

#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Audio
	{
		class SoundImpl;

		class LDL_EXPORT Sound : public Core::FastPimpl
		{
		public:
			Sound();
			SoundImpl* GetSoundImpl();
		private:
			SoundImpl* _SoundImpl;
		};
	}
}

#endif    