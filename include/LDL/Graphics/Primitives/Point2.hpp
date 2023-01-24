#ifndef LDL_Graphics_Point2_hpp
#define LDL_Graphics_Point2_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Graphics
	{
		template<typename TYPE>
		class Point2
		{
		public:
			Point2() :
				_PosX(0),
				_PosY(0)
			{
			}

			Point2(const TYPE& x, const TYPE& y) :
				_PosX(x),
				_PosY(y)
			{
			}

			const TYPE& PosX() const
			{
				return _PosX;
			}

			const TYPE& PosY() const
			{
				return _PosY;
			}

			void Pos(const TYPE& x, const TYPE& y)
			{
				_PosX = x;
				_PosY = y;
			}

			void PosX(const TYPE& x)
			{
				_PosX = x;
			}

			void PosY(const TYPE& y)
			{
				_PosY = y;
			}
		public:
			TYPE _PosX;
			TYPE _PosY;
		};
	}
}

#endif    