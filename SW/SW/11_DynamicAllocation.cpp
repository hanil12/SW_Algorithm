#include <iostream>

using namespace std;

// 메모리 영역 Heap
// - Data
//   -- 생성주기 프로그램 시작, 종료
//   -- 크기 : 상대적으로 작다.
// - Stack
//   -- 생성주기 함수 호출, 함수 반환
//   -- 크기 : 상대적으로 작다.
// - Heap
//   -- 프로그래머 영역, 생성주기 : 알아서
//   -- 크기 : 상대적으로 크다.

// 동적할당
// - 운영체제가 담당
// 사용자가 동적할당 => 운영체제(Kenel)에게 부탁 => 힙을 할당해주고 해당 주소값을 반환
// 
// malloc - free
// new - delete
// new[] - delete[]

int main()
{
#pragma region malloc-free
	void* ptr = malloc(1000);

	int* intPtr = (int*)ptr;

	for (int i = 0; i < 250; i++)
	{
		intPtr[i] = i;
	}

	free(ptr);
#pragma endregion



	return 0;
}