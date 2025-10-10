#include <iostream>

using namespace std;

// 포인터와 참조
// - 어셈블리어관점
// -- 동일하게 동작한다.

// - C++
// ref : 누군가의 별명
// => 반드시 초기화가 필요하다.(상수)
// => 한번 초기화되면 바꿀 수 없다.
// 
// 1. 안정성(ref)
// 2. 없는 값을 참조할 수 없다.(ref)
// -> ptr을 없다는 걸(nullptr)를 받을 수 있다.
// -> ref는 없는 값을 별명이 될 수 없다.

void CallByPtr(int* ptr)
{
	ptr = (int*)0x1234;
	cout << *ptr << endl;
}

void CallByRef(int& ref)
{
	int bInt = 5;
	ref = bInt;
}

class Pet
{
	bool isDead = false;
};

class Player
{
public:
	Player(Pet& pet)
	: _pet(pet)
	{

	}

	Pet& _pet;
};

int main()
{
	int aInt = 5;
	
	int* ptr = nullptr;
	int& ref = aInt;

	cout << ref << endl;

	Pet* pet = new Pet();

	Player* player = new Player(*pet);

	delete player;
	delete pet;

	return 0;
}