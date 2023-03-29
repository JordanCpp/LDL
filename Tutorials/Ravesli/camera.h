#ifndef CAMERA_H
#define CAMERA_H

#include <LDL/Math/Funcs.hpp>
#include <LDL/Math/Mat2f.hpp>
#include <LDL/Math/Mat3f.hpp>
#include <LDL/Math/Mat4f.hpp>
#include <LDL/Math/Vec2f.hpp>
#include <LDL/Math/Vec3f.hpp>
#include <LDL/Math/Vec4f.hpp>

using namespace LDL::Math;

#include <vector>

// Определяет несколько возможных вариантов движения камеры. Используется в качестве абстракции, чтобы держаться подальше от специфичных для оконной системы методов ввода
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Параметры камеры по умолчанию
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.01f;
const float ZOOM        =  45.0f;


// Абстрактный класс камеры, который обрабатывает входные данные и вычисляет соответствующие Эйлеровы углы, векторы и матрицы для использования в OpenGL
class Camera
{
public:
    // Атрибуты камеры
    Vec3f Position;
    Vec3f Front;
    Vec3f Up;
    Vec3f Right;
    Vec3f WorldUp;
    // углы Эйлера
    float Yaw;
    float Pitch;
    // Настройки камеры
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    // Конструктор, использующий векторы
    Camera(Vec3f position = Vec3f(0.0f, 0.0f, 0.0f), Vec3f up = Vec3f(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH) : Front(Vec3f(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = position;
        WorldUp = up;
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }
    // Конструктор, использующие скаляры
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) : Front(Vec3f(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM)
    {
        Position = Vec3f(posX, posY, posZ);
        WorldUp = Vec3f(upX, upY, upZ);
        Yaw = yaw;
        Pitch = pitch;
        updateCameraVectors();
    }

    // Возвращает матрицу вида, вычисленную с использованием углов Эйлера и LookAt-матрицы 
    Mat4f GetViewMatrix()
    {
        return LookAt(Position, Position + Front, Up);
    }

    //Обрабатываем входные данные, полученные от любой клавиатуроподобной системы ввода. Принимаем входной параметр в виде определенного камерой перечисления (для абстрагирования его от оконных систем)
    void ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = MovementSpeed * deltaTime;
        if (direction == FORWARD)
            Position += Front * velocity;
        if (direction == BACKWARD)
            Position -= Front * velocity;
        if (direction == LEFT)
            Position -= Right * velocity;
        if (direction == RIGHT)
            Position += Right * velocity;
    }

    //Обрабатываем входные данные, полученные от системы ввода с помощью мыши. Ожидаем в качестве параметров значения смещения как в направлении X, так и в направлении Y.
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true)
    {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw   += xoffset;
        Pitch += yoffset;

        // Убеждаемся, что когда тангаж выходит за пределы обзора, экран не переворачивается
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }

        // Обновляем значения вектора-прямо, вектора-вправо и вектора-вверх, используя обновленные значения углов Эйлера
        updateCameraVectors();
    }

    // Обрабатывает входные данные, полученные от события колеса прокрутки мыши. Интересуют только входные данные на вертикальную ось колесика 
    void ProcessMouseScroll(float yoffset)
    {
        if (Zoom >= 1.0f && Zoom <= 45.0f)
            Zoom -= yoffset;
        if (Zoom <= 1.0f)
            Zoom = 1.0f;
        if (Zoom >= 45.0f)
            Zoom = 45.0f;
    }

private:
    // Вычисляет вектор-прямо по (обновленным) углам Эйлера камеры
    void updateCameraVectors()
    {
        // Вычисляем новый вектор-прямо
        Vec3f front;
        front.x = cos(Yaw) * cos(Pitch);
        front.y = sin(Pitch);
        front.z = sin(Yaw) * cos(Pitch);
        Front = Normalize(front);
        // Также пересчитываем вектор-вправо и вектор-вверх
        Right = Normalize(Cross(Front, WorldUp));  // Нормализуем векторы, потому что их длина становится стремится к 0 тем больше, чем больше вы смотрите вверх или вниз, что приводит к более медленному движению.
        Up    = Normalize(Cross(Right, Front));
    }
};
#endif

