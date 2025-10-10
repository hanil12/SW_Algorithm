#include <iostream>

using namespace std;

// 포인터 : 가리키는 얘
// (자료형)* (변수이름) = (초기화);
// 메모리 주소값을 담는 얘
// 크기 : 32비트(4바이트), 64비트(8바이트)

// 자료형 : 포인터를 타고 들어갔을 때 있을 값의 자료형
// void* : 타고들어갔을 때 어떤 자료형이든 상관없다. => 조커

// 연산자 
// &(변수) : 주소연산자
// (변수) & (변수) : 비트 & 연산자

// (변수) * (변수) : 곱셈연산자
// *(변수) : 간접연산자(포탈연산자)
// (자료형) * : 포인터 선언

int main()
{
	int aInt = 5;

	int* ptr1 = &aInt;

	cout << *ptr1 << endl;

	#pragma region void*, 강제형변환
	/*
	void* vPtr = &aInt;
	vPtr = (void*)0x12341234;

	cout << sizeof(ptr1) << endl;

	float aFloat = 0.5f;
	ptr1 = (int*)(&aFloat);
	cout << *ptr1 << endl;
	*/
	#pragma endregion

	return 0;
}