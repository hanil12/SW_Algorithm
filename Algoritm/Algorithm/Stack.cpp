#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// stack => 팬케이크 굽고 먹기
// FILO
// 

template<typename T, typename Contaniner = vector<T>>
class Stack
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}
	void pop()
	{
		_container.pop_back();
	}
	const T& top()
	{
		return _container.back();
	}
	bool empty()
	{
		return _container.empty();
	}

private:
	Contaniner _container;
};

int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(5);
	s.push(7);
	s.push(10);

	while (true)
	{
		if(s.empty())
			break;

		cout << s.top() << endl;
		s.pop();
	}

	return 0;
}