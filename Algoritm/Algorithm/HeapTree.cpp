#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

// 힙트리
// 1. 완전이진트리(vector로 구현가능)
// 2. 최대힙(부모가 자식보다 무조건 크다)
//    최소힙(부모가 자식보다 무조건 작다)

class PriorityQueue
{
public:
	void push(const int& value)
	{

	}

	void pop()
	{

	}

private:
	vector<int> container;
};

int main()
{
	priority_queue<int> pq;

	pq.push(50);
	pq.push(40);
	pq.push(30);
	pq.push(70);
	pq.push(100);
	pq.push(20);

	while (true)
	{
		if(pq.empty())
			break;

		cout << pq.top() << endl;

		pq.pop();
	}

	return 0;
}