#include <iostream>
#include <vector>

using namespace std;

#include "MyVector.h"
#include "MyList.h"

// vector : 동적(런타임)배열
// 정적배열 <=> 동적배열   실행시간에 크기가 변할 수 있다.

// 특징
// 1. 재할당이 일어날 경우(size == capacity) 복사비용이 많이 든다.
//  ==> reserve
// 2. 중간삽입 삭제 : 시간복잡도(N)
//  ==> capacity, size가 같을 경우에는 재할당 => 복사비용 N
//  ==> 그게 아닐 경우도 뒤로 한칸 복사하기 때문에 => 복사비용 N

int main()
{
	MyVector v;

	v.reserve(1005); // capacity를 설정
	//v.resize(1005, -1); // size를 설정

	for (int i = 0; i < 1000; i++)
	{
		v.push_back(i);

		cout << "Size : " << v.size() << endl;
		cout << "Capa : " << v.capacity() << endl;
		cout << "----------------" << endl;
	}

	MyList l;

	l.push_back(1);
	l.push_back(2);
	l.push_front(3);
	l.push_back(4);

	for (int i = 0; i < l.size(); i++)
	{
		cout << l[i] << endl;
	}

	return 0;
}