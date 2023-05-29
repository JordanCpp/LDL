#ifndef LDL_Graphics_Isometric_hpp
#define LDL_Graphics_Isometric_hpp

#include <LDL/Config.hpp>
#include <LDL/Math/Vec2.hpp>

namespace LDL
{
    namespace Graphics
    {
        class LDL_EXPORT Isometric
        {
        public:
            const Math::Vec2u& CartesianToIsometric(const Math::Vec2u& pt);
            const Math::Vec2u& IsometricToCartesian(const Math::Vec2u& pt);
        private:
            LDL::Math::Vec2u _Result;
        };
    }
}

#endif