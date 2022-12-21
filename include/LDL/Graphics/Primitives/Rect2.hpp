#ifndef LDL_Graphics_Rect2_hpp
#define LDL_Graphics_Rect2_hpp

#include <LDL/Graphics/Primitives/Point2.hpp>

namespace LDL
{
	namespace Graphics
	{
		template<typename TYPE>
		class Rect2
		{
		public:
			Rect2() :
				_Pos(0, 0),
				_Size(0, 0)
			{
			}

			Rect2(const TYPE& x, const TYPE& y, const TYPE& w, const TYPE& h) :
				_Pos(x, y),
				_Size(w, h)
			{
			}

			Rect2(const Point2<TYPE>& pos, const Point2<TYPE>& size) :
				_Pos(pos),
				_Size(size)
			{
			}

			const Point2<TYPE>& Pos() const
			{
				return _Pos;
			}

			const Point2<TYPE>& Size() const
			{
				return _Size;
			}

			void Pos(const TYPE& x, const TYPE& y)
			{
				_Pos._PosX = x;
				_Pos._PosY = y;
			}

			void Size(const TYPE& x, const TYPE& y)
			{
				_Size._PosX = x;
				_Size._PosY = y;
			}

			bool Contains(const Point2<TYPE>& Pt)
			{
				return Pt.PosX() >= _Pos._PosX && Pt.PosY() >= _Pos._PosY && Pt.PosX() <= _Pos._PosX + _Size._PosX && Pt.PosY() <= _Pos._PosY + _Size._PosY;
			}
		private:
			Point2<TYPE> _Pos;
			Point2<TYPE> _Size;
		};
	}
}

#endif    