#ifndef LDL_Graphics_Camera_hpp
#define LDL_Graphics_Camera_hpp

#include <LDL/Config.hpp>
#include <LDL/Graphics/Render.hpp>

namespace LDL
{
    namespace Graphics
    {
        class CameraImpl;

        class LDL_EXPORT Camera
        {
        public:
            Camera(Render* render, const Math::Vec2u& pos, const Math::Vec2u& size);
            CameraImpl* GetCameraImpl();
            const Math::Vec2u& Pos();
            const Math::Vec2u& Size();
            void Pos(const Math::Vec2u& pos);
            void Size(const Math::Vec2u& size);
        private:
            CameraImpl* _CameraImpl;
        };
    }
}

#endif