#include <iostream>

using namespace std;

class Math
{
public:
	static int Add(int a, int b)
	{
		return a + b;
	}
};

// Data : Global , Static 

// 동적 : 실행 중에 할당하거나.. 실행 중에...
// 정적 : 컴파일 시에 끝

class Marine
{
public:
	// 일반멤버함수
	// 일반멤버함수 호출 조건
	// 1. 객체
	// 2. 소속
	void UpgradeAtk()
	{
		atk++;
	}

	int GetAtk()
	{
		return atk;
	}

	// 정적멤버함수 => 이 클래스로 만든 모든 객체들의 공용기능
	// => 개별적인 속성을 건드리면 안됌
	// => 객체가 필요 없음, 소속만 필요
	// ===> 전역함수 처럼 쓸 수 있다.
	static void UpgradeAtk_Static()
	{
		atk++;
	}

private:
	int hp = 45;
	static int atk; // 정적멤버변수 => 이 클래스로 만든 모든 객체들의 공용속성
};

int Marine::atk = 5;

int main()
{
	Marine m;

	Marine marines[10];

	// 마린 공업
	Marine::UpgradeAtk_Static();

	cout << marines[0].GetAtk() << endl;

	return 0;
}