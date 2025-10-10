#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Casting
// 암시적 캐스팅
// int temp = (int)(short 자료형)
// int temp = (int)(float 자료형)

// 업캐스팅 : 자식의 자료형 -> 부모의 자료형 (안전)
// 다운캐스팅 : 부모의 자료형 -> 자식의 자료형 (불안전)

// 캐스팅 4총사
// static_cast : 논리적으로 맞으면 컴파일할 때 OK

// dynamic_cast : 

class Player
{
public:
	virtual void Hello() abstract;
};

class Knight : public Player
{
public:
	virtual void Hello() override { cout << "Im Knight!!!" << endl; }
	void KnightSound() { cout << "Knight 사운드 출력!!!" << endl; }
};

class Mage : public Player
{
public:
	virtual void Hello() override { cout << "Im Mage!!!" << endl; }
	void MageSound() { cout << "Mage 사운드 출력!!!" << endl; }
};

int main()
{
#pragma region static_cast,dynamic_cast
	short aShort = 5;
	int aInt = aShort;

	Knight* k = new Knight();
	Mage* m = new Mage();

	//k = (Knight*)(new Player()); // 다운캐스팅 : 부모의 자료형 데이터를 자식의 자료형으로 캐스팅 => 불안전

	vector<Player*> players;
	players.push_back(static_cast<Player*>(k)); // 업캐스팅 : 자식의 자료형 데이터가 부모 자료형으로 캐스팅 => 안전
	players.push_back(m);

	//(dynamic_cast<Knight*>(players[0]))->Hello(); // 다운캐스팅
	//(dynamic_cast<Knight*>(players[1]))->Hello(); // 다운캐스팅

	for (auto p : players)
	{
		p->Hello();

		auto ptr = dynamic_cast<Knight*>(p);
		if (ptr)
		{
			ptr->KnightSound();
		}
		else
		{
			auto mage = dynamic_cast<Mage*>(p);
			mage->MageSound();
		}
	}

	int* ptr = &aInt;
	//float* tempPtr = static_cast<float*>(&aInt);

	for (auto p : players)
	{
		delete p;
	}
#pragma endregion
	
	// const_cast
	const char* hello = "Hello World!"; // 리터럴 문자 상수 : Data영역 (data, bss, rodata)

	// const_cast<char*>(hello)[0] = 'C';

	char hello2[13] = "Hello World!";

	// reinterpret_cast : 강제 형변환
	float* tempPtr = reinterpret_cast<float*>(&aInt);

	void* data = malloc(1000);

	// 1000바이트
	// 4바이트 : 헤더(패킷 종류)
	// 996바이트 : 해당 정보
	(*reinterpret_cast<int*>(data)) = 5;

	free(data);

	return 0;
}