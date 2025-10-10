#include <iostream>

using namespace std;

// Operator : 연산자
// 이항연산자
// + - 
// (정수형) / (정수형) : 몫
// (실수형) / (실수형) : 실수형 나눗셈
// (정수형) % (정수형) : 순환구조

// 비교연산자
// >, < , ==, !=

// 논리연산자
// !(논리형), || , &&

// 비트연산자
// |, &, ^ ,>> , <<

// << : 왼쪽 Shift 연산
// - 값이 두배가 된다.
// - 맨 왼쪽비트는 버려지게 된다.

// >> : 오른쪽 Shift 연산
// - 맨 오른쪽 비트는 버려지게 된다.
// - 맨 왼쪽비트는 부호를 따른다.

// ^ : xor 둘이 같으면 0, 다르면 1
// a ^ b ^ b = a (해킹보안)

// 비트 플래그
unsigned char bitFlag = 0;

const unsigned char stun = (1 << 3);
const unsigned char airbone = (1 << 2);
const unsigned char nano = (1 << 1);
const unsigned char poision = (1 << 0);

#define STUN (1 << 3)

enum State
{
	State_NONE,
	State_STUN = (1 << 3),
	State_NANO,
	State_Poison
};

int main()
{
	int aInt = 5;
	int bInt = 7;

	int cInt = aInt ^ bInt;

	cout << cInt << endl;

	bitFlag |= stun;
	bitFlag |= nano;

	if (bitFlag & STUN) // & stun : 비트마스크
	{

	}


	return 0;
}