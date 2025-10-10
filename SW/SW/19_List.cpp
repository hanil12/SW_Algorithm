#include <iostream>
#include <list>

using namespace std;

// Node
// - next
// - prev

// 리스트의 종류 :
// 1. 단일 연결 리스트
// 2. 이중 연결 리스트
// 3. 환형 연결 리스트

// 특징
// 1. 노드(prev, next, data)로 이루어져 있다.
// 2. 중간삽입 삭제의 시간복잡도가 상수이다.
// 3. K번째의 원소에 임의 접근 => 시간복잡도(N)

int main()
{
	list<int> l;

	for (int i = 0; i < 100; i++)
	{
		l.push_back(i);
		
		cout << "Size : " << l.size() << endl;
	}

	return 0;
}