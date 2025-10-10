#include <iostream>

using namespace std;

// 싱글턴
// 1. 프로세스에서 단 하나만 존재해야한다.
// 2. 전역에서 접근 가능해야한다.

class SoundManager
{
private:
	SoundManager() { cout << "SoundManager 생성!!" << endl; }
	~SoundManager() { cout << "SoundManager 삭제!!" << endl; }

public:
	static void Create() 
	{
		if(_instance == nullptr)
			_instance = new SoundManager(); 
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
			_instance = nullptr;
		}
	}

	static SoundManager* Instance()
	{
		if(_instance == nullptr)
			Create();

		return _instance;
	}

	// 멤버함수 : private영역에 있는 속성과 기능에 접근할 수 있는 유일한 수단(method)
	void PrintWarriorSound() { cout << _warriorSound << endl; }

private:
	string _warriorSound = "워리어 등장!!!";
	static SoundManager* _instance;
};

SoundManager* SoundManager::_instance = nullptr;

int main()
{
	SoundManager::Create();

	SoundManager::Instance()->PrintWarriorSound();

	SoundManager::Delete();

	return 0;
}