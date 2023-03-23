#ifndef LDL_Graphics_Isometric_hpp
#define LDL_Graphics_Isometric_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
    namespace Graphics
    {
        class LDL_EXPORT Isometric
        {
        public:
            const Point2u& CartesianToIsometric(const Point2u& pt);
            const Point2u& IsometricToCartesian(const Point2u& pt);
        private:
            Point2u _Result;
        };
    }
}

#endif