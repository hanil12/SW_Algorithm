#include <iostream>

using namespace std;

class Pet
{
	// 1000바이트
};

class Player
{
public:
	Player()
	: _pet(new Pet())
	{
	}

	Player(const Player& other)
	{
		if (other._pet != nullptr)
		{
			_pet = new Pet(*other._pet);
		}
	}

	~Player()
	{
		if(_pet != nullptr)
			delete _pet;
	}

private:
	Pet* _pet;
};

int main()
{
	Player* p = new Player();
	Player* p2 = new Player(*p);

	delete p2;
	delete p;

	return 0;
}