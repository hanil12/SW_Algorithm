
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// BFS(Breath First Search)
// 넓이 우선 탐색
// => Queue 구현
// => 길찾기에 특화

vector<vector<bool>> adjacent; // 인접 행렬
vector<bool> visited;
vector<int> parent;

void CreateGraph()
{
	adjacent = vector<vector<bool>>(7, vector<bool>(7, false));
	visited = vector<bool>(7, false);

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
	adjacent[5][6] = true;

	adjacent[6][3] = true;
	adjacent[6][5] = true;
	adjacent[6][6] = true;
}

void BFS(int start)
{
	parent = vector<int>(adjacent.size(), -1);
	parent[start] = start;
	queue<int> q;

	q.push(start);

	while (true)
	{
		if(q.empty())
			break;

		int here = q.front();
		cout << here << endl;
		q.pop();

		for (int there = 0; there < adjacent.size(); there++)
		{
			if(adjacent[here][there] == false)
				continue;

			if(visited[there] == true)
				continue;

			visited[there] = true;
			parent[there] = here;
			q.push(there);
		}
	}
}

int main()
{
	CreateGraph();

	BFS(0);

	int end = 6;
	while (true)
	{
		if(end == parent[end])
			break;

		cout << end<< "의 부모 : " << parent[end] << endl;
		end = parent[end];
	}

	return 0;
}