#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "MyVector.h"
#include "MyList.h"

// 반복자 : (순회자)
// - 의의: C++의 기본 컨테이너들에 대해서 같은 방법으로 순회할 때

int main()
{
	MyVector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	MyVector<int>::iterator iter = v.begin();

	for (iter; iter != v.end(); iter++)
	{
		cout << *iter << endl;
	}

	return 0;
}