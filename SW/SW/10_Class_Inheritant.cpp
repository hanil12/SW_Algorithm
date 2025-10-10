#include <iostream>

using namespace std;

// 상속
// is - a 관계 (단방향)
// - 재사용성의 증가

class Animal
{
public:
	Animal() { cout << "Animal 기본생성자 호출!!" << endl; }
	Animal(int temp) : temp(temp) { cout << "Animal 타입변환생성자 호출!!" << endl; }

	~Animal() { cout << "Animal의 소멸자 호출" << endl; }

	const int temp = 0;
};

class Cat : public Animal
{
public:
	Cat()
	: Animal(1)
	{ 
		cout << "Cat 기본생성자 호출!!" << endl; 
	}
	~Cat() { cout << "Cat의 소멸자 호출" << endl; }
};

int main()
{
	Cat cat;

	return 0;
}