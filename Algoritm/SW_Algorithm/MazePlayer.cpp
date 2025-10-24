#include "framework.h"
#include "MazePlayer.h"

MazePlayer::MazePlayer(shared_ptr<Maze> maze)
: _maze(maze)
{
	_maze.lock()->SetBlock(Vector(1,1), Block::PLAYER);
	_pos = _maze.lock()->StartPos();

	BFS_Method();
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

		for (int i = 0; i < 4; i++)
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
