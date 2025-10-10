#include <iostream>
#include <vector>

using namespace std;

// move : 이사

// lvalue : 왼쪽에 있을 있는 얘 => 참조
// rvalue : lvalue가 아닌 얘 => 상수

class Player
{
public:
	Player() { _pet = new int(); }
	Player(int hp) { _pet = new int(hp); }
	Player(const Player& other) 
	{
		_pet = new int(*other._pet);
	}

	// 이동생성자(이사생성자)
	Player(Player&& other) noexcept // &&: 우측값 참조
	{
		cout << "이동생성자 호출!!" << endl;

		_pet = other._pet;
		other._pet = nullptr;
	}

	~Player() 
	{ 
		if(_pet != nullptr)
			delete _pet; 
	}

	int* _pet;
};

// Call by Value
// - 원본을 복사해온다.
// - p를 아무리 수정해도 원본이 훼손되지 않는다. => p를 아무렇게나 써도 상관 없다.
//void PrintPlayer(Player p)
//{
//
//}

// Call by Ref
// - 원본을 넘긴다.
void PrintPlayer(Player& p)
{

}

// Call Address
// - 원본의 주소값을 넘긴다.
void PrintPlayer(Player* p)
{

}

// Call by RValue Ref
// - 원본을 갖고 오는데, RValue처럼 쓰겠다. => 이제 이 매개변수(원본)는 껍데기만 남는다.
void PrintPlayer(Player&& p)
{

}

int main()
{
	Player p;
	Player p2(std::move(p));

	int a = 5;
	const int temp = 5;

	unique_ptr<Player> up = make_unique<Player>(); // 스마트포인터... 중복이 안되는 ptr
	unique_ptr<Player> up2 = std::move(up);

	vector<int> v;
	v.emplace_back(1);

	return 0;
}