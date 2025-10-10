#include <iostream>

using namespace std;

// (반환자료형) (함수이름) ((매개변수)) ;
void HelloWorld(void)
{
	cout << "HelloWorld!" << endl;
}

// Stack : [반환주소값][지역변수][매개변수 : num = aInt] 값전달
// Call by Value
void AddOne(int num)
{
	num++;
	// num = 6, aInt = 5
}

int main()
{
	int aInt = 5;
	AddOne(aInt);

	cout << aInt << endl;

	return 0;
}