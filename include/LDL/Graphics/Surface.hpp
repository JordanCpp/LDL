#ifndef LDL_Graphics_Surface_hpp
#define LDL_Graphics_Surface_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>
#include "Primitives/Color.hpp"
#include <LDL/Core/FastPimpl.hpp>

namespace LDL
{
	namespace Graphics
	{
		class SurfaceImpl;

		class Surface : public LDL::Core::FastPimpl
		{
		public:
			Surface(const Point2u& size, uint8_t bytesPerPixel);
			Surface(const Point2u& size, uint8_t bytesPerPixel, const Point2u& capacity);
			~Surface();
			uint8_t* Pixels();
			const Point2u& Capacity();
			const Point2u& Size();
			size_t Bytes();
			uint8_t BytesPerPixel();
			bool Empty();
			void Clear();
			void Clear(const Color& color);
		private:
			SurfaceImpl* _SurfaceImpl;
		};
	}
}

#endif    