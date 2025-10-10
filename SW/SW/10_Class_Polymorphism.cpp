#include <iostream>

using namespace std;

// 다형성
// - 형태 다양할 수 있다.
// - 오버라이딩
// - 오버로딩

// 오버로딩
class Vector
{
public:
	Vector(int x, int y)
	: _x(x), _y(y)
	{
	}
	~Vector() = default;

	// 연산자 오버로딩
	// a + b : a와 b를 더하고 임시값을 result를 반환한다.
	Vector operator+(const Vector& other)
	{
		cout << "Vector의 덧셈!" << endl;
		Vector result(_x + other._x, _y + other._y);

		return result;
	}

	// -
	// 내적(반환자료형 int)

	// 전위연산자
	// ++a : a의 원본에다가 1을 더하고 그 원본을 반환한다.
	Vector& operator++()
	{
		_x++;
		_y++;

		return *this;
	}
	// a++ : 임시값을 만들고 a의 원본에 1을 더하고 임시값을 반환한다.
	Vector operator++(int)
	{
		Vector result = *this;
		_x++;
		_y++;

		return result;
	}

	// 복사대입연산자
	// c = (a = b) : a 에다가 b를 대입하고 a의 원본을 반환한다.
	Vector& operator=(const Vector& other)
	{
		_x = other._x;
		_y = other._y;

		return *this;
	}

	void PrintVector()
	{
		cout << "x : " << _x << endl;
		cout << "y : " << _y << endl;
	}

private:
	int _x = 0;
	int _y = 0;
};

int main()
{
	Vector v1(1,2);
	Vector v2(2,2);

	Vector v3 = v1 + v2;

	v3.PrintVector();

	return 0;
}