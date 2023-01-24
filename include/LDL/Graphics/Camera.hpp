#ifndef LDL_Graphics_Camera_hpp
#define LDL_Graphics_Camera_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace LDL
{
    namespace Graphics
    {
        class Camera
        {
        public:
            Camera(const Point2u& pos, const Point2u& size);
            const Point2u& Pos();
            const Point2u& Size();
            void PosX(size_t x);
            void PosY(size_t y);
            void SizeX(size_t x);
            void SizeY(size_t y);
        private:
            Point2u _Pos;
            Point2u _Size;
        };
    }
}

#endif