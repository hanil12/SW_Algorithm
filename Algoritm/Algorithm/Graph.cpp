#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 그래프
// - 레온하르트 오일러
// 

vector<vector<int>> adjacent_list; // 인접 리스트
vector<vector<bool>> adjacent; // 인접 행렬

// 인접리스트: 탐색시간 N
void CreateGraph_List()
{
	adjacent_list.resize(7);
	adjacent_list[0].push_back(0);
	adjacent_list[0].push_back(1);
	adjacent_list[0].push_back(2);
	adjacent_list[0].push_back(3);

	adjacent_list[1].push_back(0);
	adjacent_list[1].push_back(1);

	adjacent_list[2].push_back(0);
	adjacent_list[2].push_back(2);
	adjacent_list[2].push_back(4);
	adjacent_list[2].push_back(5);

	adjacent_list[3].push_back(0);
	adjacent_list[3].push_back(3);
	adjacent_list[3].push_back(6);

	adjacent_list[4].push_back(2);
	adjacent_list[4].push_back(4);

	adjacent_list[5].push_back(2);
	adjacent_list[5].push_back(5);

	adjacent_list[6].push_back(3);
	adjacent_list[6].push_back(6);
}

// 인접행렬 : 탐색 상수
// 인접해있지 않아도 F로 메모리가 낭비된다.
// 메모리를 주고 시간을 취한다.
void CreateGraph() 
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));
	//   0  1  2  3  4  5  6
	// 0 T  T  T  T  F  F  F
	// 1 T  T  F  F  F  F  F
	// 2 T  F  T  F  T  T  F
	// 3 T  F  F  F  F  F  T
	// 4 F  F  T  F  T  F  F
	// 5 F  F  T  F  F  T  F
	// 6 F  F  F  T  F  F  T

	adjacent[0][0] = true;
	adjacent[0][1] = true;
	adjacent[0][2] = true;
	adjacent[0][3] = true;

	adjacent[1][0] = true;
	adjacent[1][1] = true;

	adjacent[2][0] = true;
	adjacent[2][2] = true;
	adjacent[2][4] = true;
	adjacent[2][5] = true;

	adjacent[3][0] = true;
	adjacent[3][6] = true;

	adjacent[4][2] = true;
	adjacent[4][4] = true;

	adjacent[5][2] = true;
	adjacent[5][5] = true;

	adjacent[6][3] = true;
	adjacent[6][6] = true;
}

int main()
{
	CreateGraph_List();

	// 2,4가 연결되어있나?
	std::find(adjacent_list[2].begin(), adjacent_list[2].end(), 4);

	// 인접행렬
	adjacent[2][4];

	return 0;
}