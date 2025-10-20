#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

// Queue => 줄서기, 오버워치 큐
// FIFO 

template<typename T, typename Container = deque<T>>
class Queue
{

};

int main()
{
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(5);
	q.push(7);
	q.push(10);

	while (true)
	{
		if(q.empty())
			break;

		cout << q.front() << endl;

		q.pop();
	}

	return 0;
}