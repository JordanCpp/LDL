#ifndef GLM_L1_HPP
#define GLM_L1_HPP

#include <math.h>

namespace glm
{
    typedef float f32;

    const f32 PI = 3.14159265358979323846f;

    struct vec2
    {
        f32 x, y;

        vec2() : x(0), y(0) {}
        vec2(f32 _x, f32 _y) : x(_x), y(_y) {}

        vec2 operator+(const vec2& v) const { return vec2(x + v.x, y + v.y); }
        vec2 operator-(const vec2& v) const { return vec2(x - v.x, y - v.y); }
        vec2 operator*(const vec2& v) const { return vec2(x * v.x, y * v.y); }
        vec2 operator/(const vec2& v) const { return vec2(x / v.x, y / v.y); }

        vec2 operator+(f32 scalar) const { return vec2(x + scalar, y + scalar); }
        vec2 operator-(f32 scalar) const { return vec2(x - scalar, y - scalar); }
        vec2 operator*(f32 scalar) const { return vec2(x * scalar, y * scalar); }
        vec2 operator/(f32 scalar) const { return vec2(x / scalar, y / scalar); }

        vec2& operator+=(const vec2& v)
        {
            x += v.x; y += v.y;
            return *this;
        }

        vec2& operator-=(const vec2& v)
        {
            x -= v.x; y -= v.y;
            return *this;
        }

        vec2& operator*=(const vec2& v)
        {
            x *= v.x; y *= v.y;
            return *this;
        }

        vec2& operator/=(const vec2& v)
        {
            x /= v.x; y /= v.y;
            return *this;
        }

        vec2& operator+=(f32 scalar)
        {
            x += scalar; y += scalar;
            return *this;
        }

        vec2& operator-=(f32 scalar)
        {
            x -= scalar; y -= scalar;
            return *this;
        }

        vec2& operator*=(f32 scalar)
        {
            x *= scalar; y *= scalar;
            return *this;
        }

        vec2& operator/=(f32 scalar)
        {
            x /= scalar; y /= scalar;
            return *this;
        }
    };

    struct vec3
    {
        f32 x, y, z;

        vec3() : x(0), y(0), z(0) {}
        vec3(f32 _x, f32 _y, f32 _z) : x(_x), y(_y), z(_z) {}

        vec3 operator+(const vec3& v) const { return vec3(x + v.x, y + v.y, z + v.z); }
        vec3 operator-(const vec3& v) const { return vec3(x - v.x, y - v.y, z - v.z); }
        vec3 operator*(const vec3& v) const { return vec3(x * v.x, y * v.y, z * v.z); }
        vec3 operator/(const vec3& v) const { return vec3(x / v.x, y / v.y, z / v.z); }

        vec3 operator+(f32 scalar) const { return vec3(x + scalar, y + scalar, z + scalar); }
        vec3 operator-(f32 scalar) const { return vec3(x - scalar, y - scalar, z - scalar); }
        vec3 operator*(f32 scalar) const { return vec3(x * scalar, y * scalar, z * scalar); }
        vec3 operator/(f32 scalar) const { return vec3(x / scalar, y / scalar, z / scalar); }

        vec3& operator+=(const vec3& v)
        {
            x += v.x; y += v.y; z += v.z;
            return *this;
        }

        vec3& operator-=(const vec3& v)
        {
            x -= v.x; y -= v.y; z -= v.z;
            return *this;
        }

        vec3& operator*=(const vec3& v)
        {
            x *= v.x; y *= v.y; z *= v.z;
            return *this;
        }

        vec3& operator/=(const vec3& v)
        {
            x /= v.x; y /= v.y; z /= v.z;
            return *this;
        }

        vec3& operator+=(f32 scalar)
        {
            x += scalar; y += scalar; z += scalar;
            return *this;
        }

        vec3& operator-=(f32 scalar)
        {
            x -= scalar; y -= scalar; z -= scalar;
            return *this;
        }

        vec3& operator*=(f32 scalar)
        {
            x *= scalar; y *= scalar; z *= scalar;
            return *this;
        }

        vec3& operator/=(f32 scalar)
        {
            x /= scalar; y /= scalar; z /= scalar;
            return *this;
        }
    };

    inline vec3 operator+(f32 scalar, const vec3& v)
    {
        return vec3(scalar + v.x, scalar + v.y, scalar + v.z);
    }

    inline vec3 operator-(f32 scalar, const vec3& v)
    {
        return vec3(scalar - v.x, scalar - v.y, scalar - v.z);
    }

    inline vec3 operator*(f32 scalar, const vec3& v)
    {
        return vec3(scalar * v.x, scalar * v.y, scalar * v.z);
    }

    inline vec3 operator/(f32 scalar, const vec3& v)
    {
        return vec3(scalar / v.x, scalar / v.y, scalar / v.z);
    }

    struct vec4
    {
        f32 x, y, z, w;

        vec4() : x(0), y(0), z(0), w(0) {}
        vec4(f32 _x, f32 _y, f32 _z, f32 _w) : x(_x), y(_y), z(_z), w(_w) {}
        vec4(const vec3& v, f32 _w) : x(v.x), y(v.y), z(v.z), w(_w) {}

        vec4 operator+(const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
        vec4 operator-(const vec4& v) const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
        vec4 operator*(const vec4& v) const { return vec4(x * v.x, y * v.y, z * v.z, w * v.w); }
        vec4 operator/(const vec4& v) const { return vec4(x / v.x, y / v.y, z / v.z, w / v.w); }

        vec4 operator+(f32 scalar) const { return vec4(x + scalar, y + scalar, z + scalar, w + scalar); }
        vec4 operator-(f32 scalar) const { return vec4(x - scalar, y - scalar, z - scalar, w - scalar); }
        vec4 operator*(f32 scalar) const { return vec4(x * scalar, y * scalar, z * scalar, w * scalar); }
        vec4 operator/(f32 scalar) const { return vec4(x / scalar, y / scalar, z / scalar, w / scalar); }

        vec4& operator+=(const vec4& v)
        {
            x += v.x; y += v.y; z += v.z; w += v.w;
            return *this;
        }

        vec4& operator-=(const vec4& v)
        {
            x -= v.x; y -= v.y; z -= v.z; w -= v.w;
            return *this;
        }

        vec4& operator*=(const vec4& v)
        {
            x *= v.x; y *= v.y; z *= v.z; w *= v.w;
            return *this;
        }

        vec4& operator/=(const vec4& v)
        {
            x /= v.x; y /= v.y; z /= v.z; w /= v.w;
            return *this;
        }

        vec4& operator+=(f32 scalar)
        {
            x += scalar; y += scalar; z += scalar; w += scalar;
            return *this;
        }

        vec4& operator-=(f32 scalar)
        {
            x -= scalar; y -= scalar; z -= scalar; w -= scalar;
            return *this;
        }

        vec4& operator*=(f32 scalar)
        {
            x *= scalar; y *= scalar; z *= scalar; w *= scalar;
            return *this;
        }

        vec4& operator/=(f32 scalar)
        {
            x /= scalar; y /= scalar; z /= scalar; w /= scalar;
            return *this;
        }
    };

    inline vec4 operator+(f32 scalar, const vec4& v)
    {
        return vec4(scalar + v.x, scalar + v.y, scalar + v.z, scalar + v.w);
    }

    inline vec4 operator-(f32 scalar, const vec4& v)
    {
        return vec4(scalar - v.x, scalar - v.y, scalar - v.z, scalar - v.w);
    }

    inline vec4 operator*(f32 scalar, const vec4& v)
    {
        return vec4(scalar * v.x, scalar * v.y, scalar * v.z, scalar * v.w);
    }

    inline vec4 operator/(f32 scalar, const vec4& v)
    {
        return vec4(scalar / v.x, scalar / v.y, scalar / v.z, scalar / v.w);
    }

    struct mat4
    {
        f32 col[4][4];

        mat4()
        {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    col[i][j] = 0.0f;
        }

        mat4(f32 scalar)
        {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    col[i][j] = (i == j) ? scalar : 0.0f;
        }

        static mat4 identity()
        {
            return mat4(1.0f);
        }

        mat4 operator+(const mat4& m) const
        {
            mat4 res;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    res.col[i][j] = col[i][j] + m.col[i][j];
            return res;
        }

        mat4 operator-(const mat4& m) const
        {
            mat4 res;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    res.col[i][j] = col[i][j] - m.col[i][j];
            return res;
        }

        mat4 operator*(const mat4& m) const
        {
            mat4 res(0.0f);
            for (int c = 0; c < 4; ++c)
            {
                for (int r = 0; r < 4; ++r)
                {
                    float sum = 0.0f;
                    for (int k = 0; k < 4; ++k)
                    {
                        sum += col[k][r] * m.col[c][k];
                    }
                    res.col[c][r] = sum;
                }
            }
            return res;
        }

        mat4 operator*(f32 scalar) const
        {
            mat4 res;
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    res.col[i][j] = col[i][j] * scalar;
            return res;
        }

        vec4 operator*(const vec4& v) const
        {
            return vec4(
                col[0][0] * v.x + col[1][0] * v.y + col[2][0] * v.z + col[3][0] * v.w,
                col[0][1] * v.x + col[1][1] * v.y + col[2][1] * v.z + col[3][1] * v.w,
                col[0][2] * v.x + col[1][2] * v.y + col[2][2] * v.z + col[3][2] * v.w,
                col[0][3] * v.x + col[1][3] * v.y + col[2][3] * v.z + col[3][3] * v.w
            );
        }
    };

    inline f32 radians(f32 angle)
    {
        return angle * (PI / 180.0f);
    }

    inline f32 length(const vec3& v)
    {
        return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    }

    inline f32 length(const vec4& v)
    {
        return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
    }

    inline f32 dot(const vec3& a, const vec3& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z;
    }

    inline f32 dot(const vec4& a, const vec4& b)
    {
        return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    }

    inline vec3 cross(const vec3& a, const vec3& b)
    {
        return vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
    }

    inline vec3 normalize(const vec3& v)
    {
        f32 l = length(v);
        if (l == 0) return vec3(0, 0, 0);
        return vec3(v.x / l, v.y / l, v.z / l);
    }

    inline vec4 normalize(const vec4& v)
    {
        f32 l = length(v);
        if (l == 0) return vec4(0, 0, 0, 0);
        return vec4(v.x / l, v.y / l, v.z / l, v.w / l);
    }

    inline mat4 translate(const mat4& m, const vec3& v)
    {
        mat4 trans = mat4::identity();
        trans.col[3][0] = v.x;
        trans.col[3][1] = v.y;
        trans.col[3][2] = v.z;
        return m * trans;
    }

    inline mat4 scale(const mat4& m, const vec3& v)
    {
        mat4 res = m;
        res.col[0][0] *= v.x; res.col[0][1] *= v.x; res.col[0][2] *= v.x; res.col[0][3] *= v.x;
        res.col[1][0] *= v.y; res.col[1][1] *= v.y; res.col[1][2] *= v.y; res.col[1][3] *= v.y;
        res.col[2][0] *= v.z; res.col[2][1] *= v.z; res.col[2][2] *= v.z; res.col[2][3] *= v.z;
        return res;
    }

    inline mat4 rotate(const mat4& m, f32 angle, const vec3& axis)
    {
        f32 c = cosf(angle);
        f32 s = sinf(angle);
        f32 t = 1.0f - c;
        vec3 a = normalize(axis);

        mat4 rot = mat4::identity();
        rot.col[0][0] = t * a.x * a.x + c;
        rot.col[0][1] = t * a.x * a.y + s * a.z;
        rot.col[0][2] = t * a.x * a.z - s * a.y;

        rot.col[1][0] = t * a.x * a.y - s * a.z;
        rot.col[1][1] = t * a.y * a.y + c;
        rot.col[1][2] = t * a.y * a.z + s * a.x;

        rot.col[2][0] = t * a.x * a.z + s * a.y;
        rot.col[2][1] = t * a.y * a.z - s * a.x;
        rot.col[2][2] = t * a.z * a.z + c;

        return m * rot;
    }

    inline mat4 perspective(f32 fov, f32 aspect, f32 nearV, f32 farV)
    {
        f32 tanHalfFov = tanf(fov / 2.0f);
        mat4 res(0.0f);
        res.col[0][0] = 1.0f / (aspect * tanHalfFov);
        res.col[1][1] = 1.0f / (tanHalfFov);
        res.col[2][2] = -(farV + nearV) / (farV - nearV);
        res.col[2][3] = -1.0f;
        res.col[3][2] = -(2.0f * farV * nearV) / (farV - nearV);
        return res;
    }

    inline mat4 lookAt(const vec3& eye, const vec3& center, const vec3& up)
    {
        vec3 f = normalize(center - eye);
        vec3 s = normalize(cross(f, up));
        vec3 u = cross(s, f);

        mat4 res = mat4::identity();
        res.col[0][0] = s.x; res.col[0][1] = u.x; res.col[0][2] = -f.x;
        res.col[1][0] = s.y; res.col[1][1] = u.y; res.col[1][2] = -f.y;
        res.col[2][0] = s.z; res.col[2][1] = u.z; res.col[2][2] = -f.z;

        res.col[3][0] = -dot(s, eye);
        res.col[3][1] = -dot(u, eye);
        res.col[3][2] = dot(f, eye);

        return res;
    }

    inline mat4 ortho(f32 left, f32 right, f32 bottom, f32 top, f32 zNear, f32 zFar)
    {
        mat4 Result(1.0f);

        Result.col[0][0] = 2.0f / (right - left);
        Result.col[1][1] = 2.0f / (top - bottom);
        Result.col[2][2] = -2.0f / (zFar - zNear);

        Result.col[3][0] = -(right + left) / (right - left);
        Result.col[3][1] = -(top + bottom) / (top - bottom);
        Result.col[3][2] = -(zFar + zNear) / (zFar - zNear);

        return Result;
    }

    template <typename T>
    inline const float* value_ptr(const T& v)
    {
        return reinterpret_cast<const float*>(&v);
    }
}

#endif