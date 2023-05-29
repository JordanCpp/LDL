#ifndef LDL_Graphics_Rect_hpp
#define LDL_Graphics_Rect_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Graphics
	{
		template<typename TYPE>
		class Rect
		{
		public:
			Rect() :
				_Pos(0, 0),
				_Size(0, 0)
			{
			}

			Rect(const TYPE& x, const TYPE& y, const TYPE& w, const TYPE& h) :
				_Pos(x, y),
				_Size(w, h)
			{
			}

			Rect(const LDL::Math::Vec2<TYPE>& pos, const LDL::Math::Vec2<TYPE>& size) :
				_Pos(pos),
				_Size(size)
			{
			}

			const LDL::Math::Vec2<TYPE>& Pos() const
			{
				return _Pos;
			}

			const LDL::Math::Vec2<TYPE>& Size() const
			{
				return _Size;
			}

			void Pos(const TYPE& x, const TYPE& y)
			{
				_Pos.x = x;
				_Pos.y = y;
			}

			void Size(const TYPE& x, const TYPE& y)
			{
				_Size.x = x;
				_Size.y = y;
			}

			bool Contains(const LDL::Math::Vec2<TYPE>& Pt)
			{
				return Pt.x >= _Pos.x && Pt.y >= _Pos.y && Pt.x <= _Pos.x + _Size.x && Pt.y <= _Pos.y + _Size.y;
			}
		private:
			LDL::Math::Vec2<TYPE> _Pos;
			LDL::Math::Vec2<TYPE> _Size;
		};

		typedef Rect<size_t>   Rectu;
		typedef Rect<intmax_t> Recti;
	}
}

#endif    