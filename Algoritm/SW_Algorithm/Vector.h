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

    Vector& operator+=(const Vector& other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector& operator-=(const Vector& other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    bool operator==(const Vector& other)
    {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Vector& other)
    {
        return !this->operator==(other);
    }

    static int MahattanDistance(const Vector& v1, const Vector& v2)
    {
        return abs(v2.x - v1.x) + abs(v2.y - v1.y);
    }

public:
	float x;
	float y;
};

