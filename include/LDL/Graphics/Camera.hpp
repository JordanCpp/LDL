#ifndef LDL_Graphics_Camera_hpp
#define LDL_Graphics_Camera_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Primitives/Point2i.hpp>
#include <LDL/Graphics/Render.hpp>

namespace LDL
{
    namespace Graphics
    {
        class CameraImpl;

        class LDL_EXPORT Camera
        {
        public:
            Camera(Render* render, const Point2u& pos, const Point2u& size);
            CameraImpl* GetCameraImpl();
            const Point2u& Pos();
            const Point2u& Size();
            void Pos(const Point2u& pos);
            void Size(const Point2u& size);
        private:
            CameraImpl* _CameraImpl;
        };
    }
}

#endif