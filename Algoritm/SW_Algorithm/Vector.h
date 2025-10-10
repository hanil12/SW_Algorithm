#pragma once
class Vector
{
public:
	Vector() : x(0.0f), y(0.0f) {}
	Vector(float x, float y) : x(x), y(y) {}
	~Vector() {}

    float DotProduct(const Vector& other)
    {
        return x * other.x + y * other.y;
    }

    Vector operator*(float s)
    {
        x *= s;
        y *= s;

        return *this;
    }

    Vector operator+(const Vector& other)
    {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator-(const Vector& other)
    {
        return Vector(x - other.x, y - other.y);
    }

public:
	float x;
	float y;
};

