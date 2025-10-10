#include <iostream>

using namespace std;

// 사용자 정의 자료형
// struct
// - 복합자료형
// 
// enum
// - 열거형

struct Player
{
	float hp;
	short mp;
	short padding;
	int level;
};

enum State
{
	NONE,
	STUN,
	AIRBONE,
	NANO,
};

// 변수 선언
// (자료형) (변수이름) = (초기화);

// Data 영역 초기화 값
int b;

int main()
{
	// Stack 영역 초기화 값
	int a;
	Player p;
	p.hp = 0.5f;
	p.mp = 2;
	p.padding = 0;
	p.level = 1;
	cout << sizeof(Player) << endl;

	State state;

	return 0;
}