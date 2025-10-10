#include <iostream>
#include <vector>

using namespace std;

#include "Player3.h"

// 함수 오버로딩
// => 함수템플릿

// 템플릿 : 주조틀

// 함수템플릿 : 함수를 찍어내는 틀

template <typename T = int> // template의 기본인자
T Add(T a, T b) // 나중에 T라는 자료형으로 만들어줘 => 컴파일러가 코드를 작성
{
	return a + b;
}

// 템플릿 특수화
template<>
double Add(double a, double b)
{
	cout << "Double 덧셈!!" << endl;
	return a + b;
}

// 클래스 템플릿 : 클래스(설계도)를 찍어내는 틀
// 99프로 멤버변수가 T

template <typename T = int>
class Vector
{
	T operator+(const Vector<T>& other)
	{
		
	}

	T x;
	T y;
};

// 템플릿의 특수화
template<>
class Vector<double>
{
	double x;
	double y;
};

int main()
{
	Add<int>(1,2);
	Add<double>(1,2);

	Player3<int> p;
	p.HelloWorld();

	return 0;
}