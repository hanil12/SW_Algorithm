#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

// 스마트포인터
// - 우리가 new delete를 하지 않아도 자동으로 해제되는 포인터 => memory leak을 최소화
// 
// shared_ptr : 참조횟수
// weak_ptr
// unique_ptr

struct RefCount_Block
{
	int count = 0;
};

template<typename T>
class Shared_Ptr
{
public:
	Shared_Ptr() :_ptr(nullptr), _block(nullptr) {  }
	Shared_Ptr(T* ptr) : _ptr(ptr)
	{
		_block = new RefCount_Block();
		_block->count = 1;
	}
	Shared_Ptr(const Shared_Ptr<T>& other)
	{
		_block = other._block;
		_ptr = other._ptr;
		_block->count++;
		cout << "RefCount : " << _block->count << endl;
	}

	~Shared_Ptr()
	{
		_block->count--;
		cout << "RefCount : " << _block->count << endl;

		if (_block->count == 0 && _block != nullptr)
		{
			delete _ptr;
			delete _block;
		}
	}

	Shared_Ptr<T>& operator=(const Shared_Ptr<T>& other)
	{
		_block = other->_block;
		_ptr = other->_ptr;
		_block->count++;
		cout << "RefCount : " << _block->count << endl;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
	RefCount_Block* _block;
};

class Player
{
public:
	Player() { cout << "Player의 기본생성자 호출!" << endl; }
	Player(int i) { cout << "Player의 타입변환생성자 호출!" << i << endl; }
	~Player() { cout << "Player의 소멸자 호출!" << endl; }

	void PrintPlayer() { cout << "Player 출력!!" << endl; }
	void TakeDamage() { cout << "으윽!!!" << endl; }
	void Attack()
	{
		if (target.expired() == false)
		{
			cout << "target Attack!!!" << endl;
			target.lock()->TakeDamage();
		}
	}

	weak_ptr<Player> target;
};

void HelloPlayer(shared_ptr<Player> p) // shared_ptr<Player> 복사생성자
{
	p->PrintPlayer();
}

void HelloPlayer(Shared_Ptr<Player> p)
{
	p->PrintPlayer();
}

int main()
{
	shared_ptr<Player> p = make_shared<Player>(123);
	shared_ptr<Player> p2 = make_shared<Player>();

	// shared_ptr의 순환고리 문제
	p->target = p2;
	p2->target = p;

	p->Attack();
	p2->Attack();

	//p->target = nullptr;
	//p2->target = nullptr;

	return 0;
}