#include <iostream>

using namespace std;

// class : 객체를 찍어내는 설계도(건물)

// 가상함수 

// - vftable : 가상함수테이블을 가리키는 포인터가 객체의 맨 앞주소에 포함이 되어있다.
// - 동적바인딩 : 
// - RTTI : 

// 오버라이딩 : 부모의 함수를 자식에서 재정의(시그니쳐 동일, 함수이름 동일)
class Player
{
public:
	virtual ~Player() {}

	virtual void Hello() // 가상함수
	{
		cout << "Im Player!" << endl;
	}

private:
	int _hp = 1;
	int _atk = 2;
};

class Knight : public Player
{
public:
	virtual ~Knight() {}

	virtual void Hello() override
	{
		cout << "Im Knight!" << endl;
	}

private:
	int _stamina = 3;
};

int main()
{
	Player* k = new Knight(); // 업캐스팅

	k->Hello();

	delete k;

	return 0;
}