#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

// Map : 레드블랙트리 => 자가균형 이진탐색트리
// 삽입 삭제 : N logN
// Key로 탐색 : logN
// 장점 / 단점 : 메모리를 효율적으로 사용할 수 있다. 상대적으로 빠르다. 

// Unordered Map : 해쉬 테이블
// 해쉬알고리즘 , 체이닝
// 삽입 삭제 : 상수
// Key로 탐색 : (해쉬알고리즘 적용 x 인덱스 탐색) => 상수
// 장점 / 단점 : 메모리를 주고 탐색시간을 취한다.

// DataBase : 엄청 많은 데이터를 저장/관리
// 기본 Key : 자가균형이진탐색트리
// Indexing : 해쉬테이블

// 시간복잡도
// N^2
// N logN
// N
// logN
// 상수

struct User
{
	int id;
};

void Test()
{
	vector<User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user {i};
		users.push_back(user);
	}

	// id가 500인 유저를 찾겠다. => 시간복잡도 N
}

void Test2()
{
	map<int, User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user{i};
		pair<const int, User> myPair = make_pair(i, user);
		//users.insert(myPair);

		users[i] = user;
	}
}

void Test3()
{
	unordered_map<int, User> users;

	for (int i = 0; i < 1000; i++)
	{
		User user{ i };
		pair<const int, User> myPair = make_pair(i, user);
		//users.insert(myPair);

		users[i] = user;
	}
}

int main()
{

	return 0;
}