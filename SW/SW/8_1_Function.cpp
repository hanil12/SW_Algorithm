#include <iostream>

using namespace std;

struct Vector
{
	int x = 0;
	int y = 0;
};

void PrintVector(Vector v) // 출력용
{
	cout << "X : " << v.x << endl;
	cout << "Y : " << v.y << endl;
}

// 포인터의 읽기전용
void PrintVector(const Vector* const v) // 출력용
{
	cout << "X : " << v->x << endl;
	cout << "Y : " << v->y << endl;
}

// Ref의 읽기전용
void PrintVector_Ref(const Vector& v)
{
	cout << "X : " << v.x << endl;
	cout << "Y : " << v.y << endl;
}

// Call by Value
// 단점 
// - 복사비용이 든다. 
// - 원본을 수정할 수가 없다.
// 장점
// - 안전하다 => 내가 매개변수를 아무리 바꾸고 뭔짓을 해도...원본이 수정되지 않는다.
void SetVector(Vector v, int x, int y) // 8바이트
{
	v.x = x;
	v.y = y;
}

// Call by Address
// 장점
// - 복사비용이 들지 않는다.
// - 원본이 수정할 수 있다.
// 단점
// - 원본이 수정된다.
// - 불안전하다.
void SetVector(Vector* v/*0x12*/, int x, int y) // 4바이트
{
	(*v).x = x;
	v->y = y;
}

// Call by Reference
// 장점
// - 안전한다.
// - 원본수정 가능
// 단점
// - 원본수정 가능
// - Value랑 쓰는 방법이 같다.
void SetVector_Ref(Vector& vRef/*0x12*/, int x, int y)
{
	vRef.x = x;
	vRef.y = y;
}

int main()
{
	Vector v; // 0x12
	v.x = 1;
	v.y = 3;

	SetVector(&v, 5,5);
	PrintVector(v);

	return 0;
}