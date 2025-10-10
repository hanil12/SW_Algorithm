#include <iostream>

using namespace std;

// 객체
// - C++ : 기능(멤버함수)과 속성(멤버변수)을 가질 수 있는 개체
// - 공학 : 메모리 상에 올라와있고, C++ 기능까지 포함
// 인스턴스(instance)
// - 메모리상에 올라와있는 얘(객체)
// 
// 객체지향의 3속성
// 은닉성(캡슐화)
// 상속성
// 다형성(여러가지 형태를 가질 수 있다.)

// 객체지향
class Car
{
public:
	void Handling(int value) // 멤버함수 : private 속성을 수정할 수 있는 유일한 수단
	{
		_handle = value;
	}

	int GetHandle() { return _handle; }
	void SetHandle(int value) 
	{
		if(value < 0)
			return;
		_handle = value; 
	}

	int& Handle()
	{
		return _handle;
	}

private: // 접근지정자
	int _handle; // 멤버변수
	int _wheels;
	int _engine;
};

int main()
{
	Car car;

	return 0;
}