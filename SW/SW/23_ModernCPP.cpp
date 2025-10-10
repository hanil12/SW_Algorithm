#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 1. auto
// 2. 중괄호 초기화
// 3. 범위기반 for문
// 4. using 
// 5. enum, enum class 차이
// 6. friend
// 7. final, delete
// 8. 이동생성자, 이동개념
// 9. 람다식
// 10. 스마트 포인터

struct Temp
{
	int a;
	int a2;
	int a3;
	int a4;
};

typedef unsigned int UINT;
using UINT2 = unsigned int;

enum State
{
	State_NONE,
	State_SLEEP,
	State_SICK,
	State_STUN
};

enum PetState
{
	PetState_NONE,
	PetState_FUNNY
};

enum class PlayerState
{
	NONE,
	SLEEP,
	SICK
};

enum class KnightState
{
	NONE,
	RAGE,
	SICK
};

class Player;
class Pet;

class Player
{
	friend class Pet;

	int _hp;
};

class Pet
{
public:
	virtual void Temp(Player* p)
	{
		cout << p->_hp << endl;
	}

	int _tail;
};

class Cat : public Pet
{
public:
	Cat() = default;
	Cat(const Cat& other) = delete;

	virtual void Temp(Player* p) override final
	{

	}
};


int main()
{
	unordered_map<int, int> um;
	for (int i = 0; i < 10; i++)
	{
		um[i] = i + 1;
	}

	vector<int> v = {1,2,3,4,4,5,6,6,6,24,2,3};
	auto iter = um.begin();

	int arr[5] = {1,2,3,4,5};

	int aInt = {1};
	Temp t = {1,2,3,4};

	for (pair<const int,int>& element : um)
	{
		cout << "Key : " << element.first << ", Value : " << element.second << endl;
	}

	UINT2 aInt2 = static_cast<int>(PlayerState::NONE);

	State state = State_SICK;

	return 0;
}