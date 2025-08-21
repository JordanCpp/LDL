#ifndef LDL_Math_Rect_hpp
#define LDL_Math_Rect_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
	namespace Math
	{
		template<typename TYPE>
		class Rect
		{
		public:
			Rect() :
				_pos(0, 0),
				_size(0, 0)
			{
			}

			Rect(const TYPE& x, const TYPE& y, const TYPE& w, const TYPE& h) :
				_pos(x, y),
				_size(w, h)
			{
			}

			Rect(const Vec2<TYPE>& pos, const Vec2<TYPE>& size) :
				_pos(pos),
				_size(size)
			{
			}

			const Vec2<TYPE>& Pos() const
			{
				return _pos;
			}

			const Vec2<TYPE>& Size() const
			{
				return _size;
			}

			void Pos(const TYPE& x, const TYPE& y)
			{
				_pos.x = x;
				_pos.y = y;
			}

			void Size(const TYPE& x, const TYPE& y)
			{
				_size.x = x;
				_size.y = y;
			}

			bool Contains(const Vec2<TYPE>& Pt)
			{
				return Pt.x >= _pos.x && Pt.y >= _pos.y && Pt.x <= _pos.x + _size.x && Pt.y <= _pos.y + _size.y;
			}
		private:
			Vec2<TYPE> _pos;
			Vec2<TYPE> _size;
		};

		typedef Rect<float>    Rectf;
		typedef Rect<intmax_t> Recti;
		typedef Rect<size_t>   Rectu;
	}
}

#endif    
