#ifndef LDL_Math_Vec3_hpp
#define LDL_Math_Vec3_hpp

#include <LDL/Core/Types.hpp>

namespace LDL
{
	namespace Math
	{
		template<typename T>
		class Vec3
		{
		public:
			Vec3()
			{
				x = 0;
				y = 0;
				z = 0;
			}

			Vec3(T v1, T v2, T v3)
			{
				x = v1;
				y = v2;
				z = v3;
			}

			Vec3(T v)
			{
				x = v;
				y = v;
				z = v;
			}

			Vec3<T> operator + (const Vec3<T>& source) const
			{
				Vec3<T> result;

				result.x = x + source.x;
				result.y = y + source.y;
				result.z = z + source.z;

				return result;
			}

			Vec3<T> operator - (const Vec3<T>& source) const
			{
				Vec3<T> result;

				result.x = x - source.x;
				result.y = y - source.y;
				result.z = z - source.z;

				return result;
			}

			Vec3<T> operator += (const Vec3<T>& right)
			{
				x += right.x;
				y += right.y;
				z += right.z;

				return *this;
			}

			Vec3<T> operator -= (const Vec3<T>& right)
			{
				x -= right.x;
				y -= right.y;
				z -= right.z;

				return *this;
			}

			Vec3<T> operator * (const Vec3<T>& source) const
			{
				Vec3<T> result;

				result.x = x * source.x;
				result.y = y * source.y;
				result.z = z * source.z;

				return result;
			}

			Vec3<T> operator * (const T& source) const
			{
				Vec3<T> result;

				result.x = x * source;
				result.y = y * source;
				result.z = z * source;

				return result;
			}

			T x;
			T y;
			T z;
		};
	}
}

#endif     