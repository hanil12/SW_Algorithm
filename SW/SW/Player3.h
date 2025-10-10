#pragma once

// 파일분할 => 결합을 해야 쓸 수 있음
// ==> 링커 : obj(파일 결합) 파일 생성

#include <iostream>

using namespace std;

template <typename T>
class Player3
{
public:
	Player3() : _hp(10) {}

	void HelloWorld();

	
	T _hp;
};

template<typename T>
inline void Player3<T>::HelloWorld()
{
	cout << _hp << endl;
	cout << "Hello World!" << endl;
}
