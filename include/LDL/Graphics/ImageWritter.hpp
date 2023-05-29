#ifndef LDL_Graphics_ImageWritter_hpp
#define LDL_Graphics_ImageWritter_hpp

#include <LDL/Config.hpp>
#include <LDL/Math/Vec2.hpp>
#include <string>

namespace LDL
{
	namespace Graphics
	{
		class LDL_EXPORT ImageWritter
		{
		public:
			void Save(const std::string& path, const Math::Vec2u& size, size_t bytesPerPixel, uint8_t* pixels);
		private:
		};
	}
}

#endif    