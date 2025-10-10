#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v{ 12,3,3,452,5,12,4,1 };

	// [캡쳐부](매개변수)-> (반환자료형) {정의부} 
	// [](const int&) -> bool{}

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

	int compareNum = 15;

	auto iter = std::find_if(v.begin(), v.end(), [&compareNum](const int& element)-> bool
	{
			if (element < compareNum)
				return true;
			return false;
	});

	cout << *iter << endl;


	return 0;
}