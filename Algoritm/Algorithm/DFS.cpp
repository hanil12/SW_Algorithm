#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS(Deep First Search)
// 재귀호출 <=> 반복문

vector<vector<bool>> adjacent; // 인접 행렬
vector<bool> visited;

void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));
	visited = vector<bool>(7, false);
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

void DFS(int here)
{
	visited[here] = true;
	cout << here << " 방문!!" << endl;

	for (int there = 0; there < adjacent.size(); there++)
	{
		if(here == there)
			continue;

		// 인접해있냐?
		if(adjacent[here][there] == false)
			continue;

		// 방문되어있는지?
		if(visited[there])
			continue;

		DFS(there);
	}
}

int main()
{
	CreateGraph();
	DFS(0);

	return 0;
}