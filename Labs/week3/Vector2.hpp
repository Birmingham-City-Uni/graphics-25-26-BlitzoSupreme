#pragma once
#include <ostream>
#include <stdexcept>

class Vector2
{
public:
    Vector2() : x_(0.0f), y_(0.0f) {}
    Vector2(float x, float y) : x_(x), y_(y) {}

    Vector2 operator+(const Vector2& o) const { return Vector2(x_ + o.x_, y_ + o.y_); }
    Vector2 operator-(const Vector2& o) const { return Vector2(x_ - o.x_, y_ - o.y_); }
    Vector2 operator*(float s) const { return Vector2(x_ * s, y_ * s); }

    // Task 1: Dot product (2D)
    static float dot(const Vector2& a, const Vector2& b)
    {
        return a.x_ * b.x_ + a.y_ * b.y_;
    }

    // Task 1: Cross product (2D) -> scalar "z-component" of 3D cross
    // cross(a,b) = a.x*b.y - a.y*b.x
    static float cross(const Vector2& a, const Vector2& b)
    {
        return a.x_ * b.y_ - a.y_ * b.x_;
    }

    float& operator[](int i)
    {
        if (i == 0) return x_;
        if (i == 1) return y_;
        throw std::out_of_range("Vector2 index must be 0 or 1");
    }
    float operator[](int i) const
    {
        if (i == 0) return x_;
        if (i == 1) return y_;
        throw std::out_of_range("Vector2 index must be 0 or 1");
    }

    const float& x() const { return x_; }
    float& x() { return x_; }
    const float& y() const { return y_; }
    float& y() { return y_; }

private:
    float x_, y_;
};

inline Vector2 operator*(float s, const Vector2& v) { return v * s; }

inline std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
    os << "(" << v[0] << ", " << v[1] << ")";
    return os;
}