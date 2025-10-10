#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v { 12,3,3,452,5,12,4,1};

	//v.shrink_to_fit(); // cap == size
	//v.clear();

	//vector<int>().swap(v); // 임시객체

	//cout << v.capacity() << endl;
	//cout << v.size() << endl;

	// 1. v에서 452이라는 값이 있는지 찾고, iterator 혹은 index를 찾으시오

	// 2. v에서 3보다 작은 수가 있는지 찾고, iterator 혹은 index 찾기
	struct Find_if_Functor
	{
		bool operator()(const int& element)
		{
			if (element == compareNum)
				return true;
			return false;
		}

		int compareNum;
	};

	Find_if_Functor findIfFunctor;
	findIfFunctor.compareNum = 452;
	auto iter = std::find_if(v.begin(), v.end(), findIfFunctor);

	// C# : MSDN
	// C++ : CPP Ref
	// Python : 

	// 3. v에서 모든 수가 1보다 큰지 bool
	// std::all_of
	
	
	// 4. v에서 하나라도 400보다 큰 수가 있는지 bool
	// std::any_of
	
	// 5. v에서 15보다 작은 수 세기 int
	// count_if

	// 6. v에서 모든 수에 x2
	// for_each

	// 7. v에서 중복된 원소 제거
	// std::unique
	//vector<int>().swap(v);
	std::sort(v.begin(), v.end(), less<int>()); //  less<int>() : 무명객체, 임시객체 // n x logn
	v.erase(std::unique(v.begin(), v.end()), v.end()); // n

	// 8. v를 거꾸로 뒤집기
	// std::reverse

	// 9. v에서 6인 원소 제거
	v.erase(std::remove(v.begin(), v.end(),6),v.end());

	// 10. v에서 20보다 큰 수 제거

	auto i = v.begin();
	for (; i != v.end();)
	{
		if (*i == 12)
		{
			i = v.erase(i);
			continue;
		}

		i++;
	}

	return 0;
}