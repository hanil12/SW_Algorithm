#include <iostream>

using namespace std;

// 함수포인터 : 함수도 어딘가에는 저장이 되어있다. 그걸 간접적으로 호출해줄 수 있을까?

// 함수 포인터 선언

// 콜백함수 : 매개변수로 함수포인터,함수객체,Callable 객체를 넘겨서 나중에 호출하도록 하는 것

void(*fn)(int);

class Pet;

typedef void(*FN)(void); // 자료형 선언
typedef int(*FN2)(int,int);
typedef void(Pet::*PetFN)(void); // Pet의 멤버함수를 가리키실 수 있는 포인터 선언

void HelloWorld(void)
{
	cout << "Hello World" << endl;
}

int Add(int a, int b)
{
	return a + b;
}

class Pet
{
public:
	void Bark() { cout << "왈왈!!!" << endl; }
	void Eat() { cout << "먹기" << endl; }
};

class Player
{
public:
	void PetAction(Pet* pet, PetFN petAction)
	{
		if(pet == nullptr)
			return;

		if (petAction == nullptr)
		{
			cout << "펫이 아무런 행동도 하지 않습니다." << endl;
			return;
		}

		(pet->*petAction)();
	}

private:
	Pet* _pet;
};

int main()
{
	FN myFn;
	FN2 myFn2;

	myFn = &HelloWorld;
	myFn2 = &Add;

	cout << myFn2(1,3) << endl;

	PetFN myFn3 = &Pet::Bark;
	Pet* pet = new Pet();

	//(pet->*myFn3)();

	// -------------------------------
	Player* player = new Player();

	player->PetAction(pet, nullptr);

	player->PetAction(pet, &Pet::Eat);

	player->PetAction(pet, &Pet::Bark);

	delete player;
	delete pet;

	return 0;
}