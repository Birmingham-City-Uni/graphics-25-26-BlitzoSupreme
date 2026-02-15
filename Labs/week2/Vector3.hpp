#pragma once

#include <ostream>
#include <stdexcept>

// *** Your Code Here! ***
// * Task 1: I've started off a class here to store and manipulate 3D floating-point vectors.
//           We'll need to use this to load and draw the triangle mesh from the OBJ file.
//           Complete the functions indicated, so we can use the Vector3 class to draw our mesh!

class Vector3
{
public:
	// Default constructor: set all components to zero
	Vector3()
		: x_(0.0f), y_(0.0f), z_(0.0f)
	{
	}

	// Constructor: set components from inputs
	Vector3(float x, float y, float z)
		: x_(x), y_(y), z_(z)
	{
	}

	// Add two vectors
	Vector3 operator+(const Vector3& other) const
	{
		return Vector3(x_ + other.x_, y_ + other.y_, z_ + other.z_);
	}

	// Multiply by a scalar
	Vector3 operator*(float scalar) const
	{
		return Vector3(x_ * scalar, y_ * scalar, z_ * scalar);
	}

	// Non-const index operator (returns reference so caller can modify component)
	float& operator[](int i)
	{
		if (i == 0) return x_;
		if (i == 1) return y_;
		if (i == 2) return z_;
		throw std::out_of_range("Vector3 index must be 0, 1, or 2");
	}

	// Const index operator
	float operator[](int i) const
	{
		if (i == 0) return x_;
		if (i == 1) return y_;
		if (i == 2) return z_;
		throw std::out_of_range("Vector3 index must be 0, 1, or 2");
	}

	// Getters (already provided)
	const float& x() const { return x_; }
	float& x() { return x_; }

	const float& y() const { return y_; }
	float& y() { return y_; }

	const float& z() const { return z_; }
	float& z() { return z_; }

private:
	float x_, y_, z_;
};

// scalar * vector
inline Vector3 operator*(float scalar, const Vector3& vector)
{
	return vector * scalar;
}

// print helper
inline std::ostream& operator<<(std::ostream& stream, const Vector3& v)
{
	stream << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
	return stream;
}