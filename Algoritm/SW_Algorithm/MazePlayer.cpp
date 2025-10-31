#include "framework.h"
#include "MazePlayer.h"

MazePlayer::MazePlayer(shared_ptr<Maze> maze)
: _maze(maze)
{
	_maze.lock()->SetBlock(Vector(1,1), Block::PLAYER);
	_pos = _maze.lock()->StartPos();

	AStar({_maze.lock()->StartPos(), 0,0,0}, { _maze.lock()->EndPos(), 0,0,0 });
}

MazePlayer::~MazePlayer()
{
}

void MazePlayer::Update()
{
	if (_pathIndex >= _path.size())
	{
		return ;
	}

	_time += 0.5f;

	if (_time > 1.0f)
	{
		_time = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex != 0)
		{
			// 발자취
		}

		_pathIndex++;
	}

	_maze.lock()->SetBlock(_pos, Block::BlockType::PLAYER);
}

void MazePlayer::RightHand()
{
	shared_ptr<Maze> maze;
	if (_maze.expired() == false)
	{
		maze = _maze.lock();
	}
	Vector pos = maze->StartPos();
	Vector endPos = maze->EndPos();
	_dir = Dir::UP;

	// 우수법으로 길을 찾으면서 _path에 추가
	while (true)
	{
		if(pos == maze->EndPos())
			break;

		int newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT; // 오른쪽
		Vector oldDirPos = pos + frontPos[_dir];
		Vector newDirPos = pos + frontPos[newDir];

		// 오른쪽이 뚫려있냐?
		if (Cango(newDirPos))
		{
			_dir = static_cast<Dir>(newDir);
			pos = newDirPos;
			_path.push_back(pos);
		}
		// 오른쪽 막혀있는데, 앞쪽은 뚫려있다?
		else if (Cango(oldDirPos))
		{
			pos = oldDirPos;
			_path.push_back(pos);
		}
		// 오른쪽 막혀있고, 앞쪽도 막혀있다. => 왼쪽 회전
		else
		{
			_dir = static_cast<Dir>((_dir + 1 + DIR_COUNT) % DIR_COUNT);
		}
	}

	stack<Vector> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();
		}
		else
		{
			s.push(_path[i]);
		}
	}

	s.push(_path.back());
	_path.clear();

	while (true)
	{
		if(s.empty())
			break;

		_path.push_back(s.top());
		s.pop();
	}

	std::reverse(_path.begin(), _path.end());
}

void MazePlayer::DFS_Method()
{
	shared_ptr<Maze> maze = _maze.lock();
	Vector start = maze->StartPos();
	vector<vector<bool>> visited; // visited[1][1] == true
	visited = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));

	DFS(start, visited, maze);
	_path.push_back(maze->EndPos());
}

void MazePlayer::BFS_Method()
{
	shared_ptr<Maze> maze = _maze.lock();
	Vector start = maze->StartPos();
	Vector end = maze->EndPos();

	vector<vector<bool>> visited = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	queue<Vector> q;
	vector<vector<Vector>> parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1,-1))); // [2][1] ... [1][1]

	visited[start.y][start.x] = true;
	q.push(start);
	parent[start.y][start.x] = start;

	while (true)
	{
		if(q.empty())
			break;

		Vector here = q.front();
		q.pop();

		if(here == end)
			break;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];
			// 인접체크
			if(Cango(there) == false)
				continue;

			// 방문체크
			if(visited[there.y][there.x] == true)
				continue;

			visited[there.y][there.x] = true;
			q.push(there);
			parent[there.y][there.x] = here;

			maze->SetBlock(there, Block::BlockType::FOOT_PRINT);
		}
	}

	Vector pos = end;
	while (true)
	{
		if(pos == start)
			break;

		_path.push_back(pos);
		pos = parent[pos.y][pos.x];
	}

	_path.push_back(start);
	std::reverse(_path.begin(), _path.end());
}

void MazePlayer::Djikstra(Vertex_Djikstra startV)
{
	priority_queue<Vertex_Djikstra, vector<Vertex_Djikstra>, greater<Vertex_Djikstra>> pq;
	vector<vector<Vector>> parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1))); // [2][1] ... [1][1]
	vector<vector<int>> best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));

	Vector start = startV.v;
	pq.push(startV);
	best[start.y][start.x] = 0;
	parent[start.y][start.x] = start;

	while (true)
	{
		if(pq.empty())
			break;

		Vertex_Djikstra hereV = pq.top();
		Vector here = hereV.v;
		pq.pop();

		if(here == _maze.lock()->EndPos())
			break;

		// 이미 발견된 곳의 best가 더 좋으면 다음
		if(best[here.y][here.x] < hereV.cost)
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];

			// 인접한지
			if(Cango(there) == false)
				continue;

			int newCost = 0;
			if (i < 4)
			{
				newCost = best[here.y][here.x] + 10; // 상하좌우
			}
			else
			{
				newCost = best[here.y][here.x] + 14; // 대각
			}
		
			// 새로찾은 가중치가 전에 있던 거보다 크면... continue;
			if(newCost >= best[there.y][there.x])
				continue;

			Vertex_Djikstra thereV = {there, newCost};
			pq.push(thereV);
			best[there.y][there.x] = newCost;
			parent[there.y][there.x] = here;

			_maze.lock()->SetBlock(there, Block::BlockType::FOOT_PRINT);
		}
	}

	Vector pos = _maze.lock()->EndPos();
	while (true)
	{
		if (pos == start)
			break;

		_path.push_back(pos);
		pos = parent[pos.y][pos.x];
	}

	_path.push_back(start);
	std::reverse(_path.begin(), _path.end());
}

void MazePlayer::AStar(Vertex startV, Vertex endV)
{
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
	vector<vector<Vector>> parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1))); // [2][1] ... [1][1]
	vector<vector<int>> best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));

	startV.g = 0;
	startV.h = Vector::MahattanDistance(startV.v, endV.v) * 10;
	startV.f = startV.g + startV.h;

	Vector start = startV.v;
	pq.push(startV);
	best[start.y][start.x] = startV.f;
	parent[start.y][start.x] = start;

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		Vector here = hereV.v;
		pq.pop();

		if (here == endV.v)
			break;

		// 이미 발견된 곳의 best가 더 좋으면 다음
		if (best[here.y][here.x] < hereV.f)
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];

			// 인접한지
			if (Cango(there) == false)
				continue;

			int newG = 0;
			int newH = 0;
			int newF = 0;
			if (i < 4)
			{
				newG = hereV.g + 10; // 상하좌우
			}
			else
			{
				newG = hereV.g + 14; // 대각
			}

			newH = Vector::MahattanDistance(there, endV.v) * 10;
			newF = newG + newH;

			// 새로찾은 가중치가 전에 있던 거보다 크면... continue;
			if (newF >= best[there.y][there.x])
				continue;

			Vertex thereV = {there, newG, newH, newF};
			pq.push(thereV);
			best[there.y][there.x] = newF;
			parent[there.y][there.x] = here;

			_maze.lock()->SetBlock(there, Block::BlockType::FOOT_PRINT);
		}
	}

	Vector pos = _maze.lock()->EndPos();
	while (true)
	{
		if (pos == start)
			break;

		_path.push_back(pos);
		pos = parent[pos.y][pos.x];
	}

	_path.push_back(start);
	std::reverse(_path.begin(), _path.end());
}

bool MazePlayer::Cango(Vector pos)
{
	Block::BlockType type = _maze.lock()->GetBlockType(pos);
	if(type == Block::BlockType::DISABLE)
		return false;
	return true;
}

void MazePlayer::DFS(Vector here, vector<vector<bool>>& visited, shared_ptr<Maze> maze)
{
	if(maze->GetBlockType(here) == Block::BlockType::DISABLE)
		return;

	if (here == maze->EndPos())
		return;

	visited[here.y][here.x] = true;

	for (int i = 0; i < 4; i++)
	{
		Vector there = here + frontPos[i];

		// 인접해있고, 갈 수 있는 길인지
		if(Cango(there) == false)
			continue;

		// 방문되었는지
		if(visited[there.y][there.x] == true)
			continue;

		_path.push_back(there);
		DFS(there, visited, maze);
	}
}
