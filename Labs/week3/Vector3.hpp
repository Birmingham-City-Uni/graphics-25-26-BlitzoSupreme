#pragma once
#include <ostream>
#include <stdexcept>
#include <cmath>

class Vector3
{
public:
    Vector3() : x_(0.0f), y_(0.0f), z_(0.0f) {}
    Vector3(float x, float y, float z) : x_(x), y_(y), z_(z) {}

    Vector3 operator+(const Vector3& o) const { return Vector3(x_ + o.x_, y_ + o.y_, z_ + o.z_); }
    Vector3 operator-(const Vector3& o) const { return Vector3(x_ - o.x_, y_ - o.y_, z_ - o.z_); }
    Vector3 operator*(float s) const { return Vector3(x_ * s, y_ * s, z_ * s); }

    // Task 1: Dot product (3D)
    static float dot(const Vector3& a, const Vector3& b)
    {
        return a.x_ * b.x_ + a.y_ * b.y_ + a.z_ * b.z_;
    }

    // Task 1: Cross product (3D) -> Vector3
    static Vector3 cross(const Vector3& a, const Vector3& b)
    {
        return Vector3(
            a.y_ * b.z_ - a.z_ * b.y_,
            a.z_ * b.x_ - a.x_ * b.z_,
            a.x_ * b.y_ - a.y_ * b.x_
        );
    }

    float length() const { return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_); }
    Vector3 normalized() const
    {
        float len = length();
        if (len <= 0.0f) return Vector3(0, 0, 0);
        return (*this) * (1.0f / len);
    }

    float& operator[](int i)
    {
        if (i == 0) return x_;
        if (i == 1) return y_;
        if (i == 2) return z_;
        throw std::out_of_range("Vector3 index must be 0, 1, or 2");
    }
    float operator[](int i) const
    {
        if (i == 0) return x_;
        if (i == 1) return y_;
        if (i == 2) return z_;
        throw std::out_of_range("Vector3 index must be 0, 1, or 2");
    }

    const float& x() const { return x_; }
    float& x() { return x_; }
    const float& y() const { return y_; }
    float& y() { return y_; }
    const float& z() const { return z_; }
    float& z() { return z_; }

private:
    float x_, y_, z_;
};

inline Vector3 operator*(float s, const Vector3& v) { return v * s; }

inline std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
    os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}