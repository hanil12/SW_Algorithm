#include <iostream>

using namespace std;

// 포인터
// +, ++ : 포인터의 자료형의 따라 얼마나 더해질지가 결정된다.
// [정수] : 임의접근연산자

// 배열
// - 메모리 상에서 연속적으로 데이터가 배치되어있다.
// - 배열의 이름은 포인터처럼 동작한다.
// -- 만약 내가 n번 째 인덱스에 접근하고 싶다. => 시간복잡도(상수)

// 더블포인터

// 함수 시그니쳐 : (반환자료형) ()(매개변수)
void Temp(int* ptr, int size);
void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];
	}

}

void Temp(int* ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int temp = *(ptr + i);
	}
}

void PrintArr2(int arr[][2], int size)
{

}

int main()
{
	__int64 aInt = 1;
	__int64* ptr = &aInt;

	cout << "a의 주소값 : " << &aInt << endl;
	cout << ptr << endl;
	ptr = ptr + 5;
	cout << ptr << endl;

	// 정적배열
	int arr[5] = {1,2,3,4,5};
	int* ptr2 = arr;

	PrintArr(arr, 5);
	Temp(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		cout << *(arr + i) << endl;
	}

	int** d_ptr = &ptr2;

	int arr2[2][2] = {{1,2},{3,4}};

	return 0;
}