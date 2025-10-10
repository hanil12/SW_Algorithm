#include <iostream>

using namespace std;

// 생성자
// - 역할 : - 초기화
// -        - 객체를 생성할 때 무조건 거쳐야하는 것

// 소멸자
// - 역할 : 동적할당 해제, 기본값으로 초기화
//         - 해제할 때 무조건 거쳐야한다.

class Player
{
public:
	// 기본생성자 : 암묵적생성자
	Player()
	: _hp(0)
	, _atk(0) // 빠른초기화 영역
	, temp(100)
	{
		// 느린 초기화 영역
		_hp = 0;

		cout << "기본 생성자 호출" << endl;
	}

	// 매개변수가 있는 생성자, 타입변환 생성자
	Player(int hp)
	: _hp(hp)
	, _atk(0)
	, temp(2000)
	{
		cout << "타입변환 생성자 호출!!" << endl;
	}

	// 복사생성자
	Player(const Player& other)
	: temp(other.temp)
	, _hp(other._hp)
	, _atk(other._atk)
	{
		cout << "복사생성자 호출!!" << endl;
	}

	~Player()
	{
		cout << "소멸자 호출!!" << endl;
	}

private:
	int _hp = 0;
	int _atk;

	const int temp;
};

int main()
{
	Player p;
	Player p2 = 10;
	// Player p3(p);


	return 0;
}