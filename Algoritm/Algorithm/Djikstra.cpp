
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// BFS(Breath First Search)
// 넓이 우선 탐색
// => Queue 구현
// => 길찾기에 특화

vector<vector<int>> adjacent; // 인접 행렬
vector<int> best;
vector<int> parent;

void CreateGraph()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));
	best = vector<int>(7, INT_MAX);

	adjacent[0][0] = 0;
	adjacent[0][1] = 5;
	adjacent[0][2] = 15;
	adjacent[0][3] = 3;

	adjacent[1][0] = 5;
	adjacent[1][1] = 0;

	adjacent[2][0] = 15;
	adjacent[2][2] = 0;
	adjacent[2][4] = 7;
	adjacent[2][5] = 3;

	adjacent[3][0] = 3;
	adjacent[3][6] = 2;
	adjacent[3][3] = 0;

	adjacent[4][2] = 7;
	adjacent[4][4] = 0;

	adjacent[5][2] = 3;
	adjacent[5][5] = 0;
	adjacent[5][6] = 4;

	adjacent[6][3] = 2;
	adjacent[6][5] = 4;
	adjacent[6][6] = 0;
}

struct Vertex
{
	int v;

	int cost;

	bool operator<(const Vertex& other) const
	{
		if(cost < other.cost)
			return true;

		return false;
	}

	bool operator>(const Vertex& other) const
	{
		if(cost > other.cost)
			return true;

		return false;
	}
};

void Djikstra(int start)
{
	priority_queue<Vertex,vector<Vertex>, greater<Vertex>> pq;
	parent = vector<int>(adjacent.size(), -1);
	best[start] = 0;
	parent[start] = start;

	Vertex startEdge = { start, 0 };
	pq.push(startEdge);

	while (true)
	{
		if(pq.empty())
			break;

		Vertex hereV = pq.top();
		pq.pop();

		// 전에 발견한 곳이 더 좋은 경로였다.
		if (best[hereV.v] < hereV.cost)
		{
			cout << hereV.v << endl;
			cout << hereV.cost << endl;
			cout << best[hereV.v] << endl;

			continue;
		}

		for (int there = 0; there < adjacent.size(); there++)
		{
			int here = hereV.v;

			// 자기 자신인지
			if(here == there)
				continue;

			// 연결되어있는지
			if(adjacent[here][there] < 0)
				continue;

			// 지금 here의 best 값 + there까지의 간선의 길이
			int newCost = best[here] + adjacent[here][there];

			// 이전에 발견한 곳의 best가 더 작거나 같으면 pq에 삽입X
			if(newCost >= best[there])
				continue;

			Vertex thereV;
			thereV.v = there;
			thereV.cost = newCost;

			pq.push(thereV);
			best[there] = newCost;
			parent[there] = here;
		}
	}
}

int main()
{
	CreateGraph();
	Djikstra(0);

	int end = 4;
	while (true)
	{
		if (end == parent[end])
			break;

		cout << end << "의 부모 : " << parent[end] << endl;
		end = parent[end];
	}

	cout << 0 << "부터 " << 4 << "까지의 거리는 ..." << best[4] << endl;

	return 0;
}