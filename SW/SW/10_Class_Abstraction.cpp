#include <iostream>

using namespace std;

// 추상 : 객체화 시킬 수 없게 만든다. => 개념으로 만든다.
// 추상클래스

// 순수가상함수 : 
// - 문법: 순수가상함수가 포함된 클래스는 객체화될 수 없다.
// - 프로그래머 입장 : 순수가상함수를 재정의하지않으면 객체로 쓸 수가 없구나. => 무조건 오버라이딩(재정의)해라.
// ==> 기능구현 무조건 해라
// ==> 인터페이스 구현

// UI
// 게임에서 인벤토리를 열려고한다.
// 인터페이스 => 접근하는데 필요한 수단, 키
// 

class Bank
{
public:
	// 멤버함수 : 기능, 속성에 접근하기 위한 수단
	virtual void AccountInfo() abstract;
protected:
	int money;
};

class KakaoBank : public Bank
{
public:
	virtual void AccountInfo() override
	{
		cout << "안녕하세요 카카오 뱅크입니다." << endl;
		cout << money << endl;
	}
};

class ShinBank : public Bank
{
public:

};

int main()
{
	//Bank* b = new Bank();
	KakaoBank* k = new KakaoBank();

	return 0;
}