#include <iostream>

using namespace std;

// 메모리 4영역
// CODE : 코드
// DATA : 전역변수, 정적변수(static)
// STACK : StackFrame[반환주소값][지역변수][매개변수]
// - 컴파일할 때 크기가 결정
// 
// HEAP

// 전역
int aInt = 1; // DATA...data
int bInt; // DATA...bss

// main[매개변수: void][temp(주소값), cInt(3)] HelloWorld[지역변수 : a = 1][매개변수 : num = 3]
void HelloWorld(int num)
{
	int a = 1;
	cout << "Hello World!" << endl;
}

// 함수 오버로딩 : 함수 이름이 같고, 매개변수의 자료형이나 개수가 달라도 통과
int AddNum(int num1, int num2)
{
	int result = num1 + num2;

	return result;
}

int AddNum(int num1, int num2, int num3, int num4 = 5)
{
	return AddNum(num1, num2) + num3;
}

int Factorial(int num)
{
	// 기저사항 : StackOverFlow
	if(num == 1)
		return 1;

	if(num == 2)
		return 2;

	return Factorial(num -1) * num;
}

int& Test_Out(int& ref)
{
	int dInt = 10;

	ref = dInt;

	return ref;
}

int main()
{ // 지역
	cout << aInt << endl;

	const char* temp = "Hanil"; // 리터럴 상수.. rodata
	int cInt = AddNum(1,2);

	// 5! : 120
	HelloWorld(5);
	// main[매개변수: void][temp(주소값), cInt(3)]



	return 0;
}