#ifndef LDL_Math_Isometric_hpp
#define LDL_Math_Isometric_hpp

#include <LDL/Math/Vec2.hpp>

namespace LDL
{
    namespace Math
    {
        class LDL_LIBRARY Isometric
        {
        public:
            const Vec2u& CartesianToIsometric(const Vec2u& pt);
            const Vec2u& IsometricToCartesian(const Vec2u& pt);
        private:
            Vec2u _result;
        };
    }
}

#endif
