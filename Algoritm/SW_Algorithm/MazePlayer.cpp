#include "framework.h"
#include "MazePlayer.h"

MazePlayer::MazePlayer(shared_ptr<Maze> maze)
: _maze(maze)
{
	_maze.lock()->SetBlock(Vector(1,1), Block::PLAYER);
	_pos = _maze.lock()->StartPos();

	RightHand();
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

	_time += 0.1f;

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

	Vector frontPos[4] =
	{
		Vector {0, -1}, // UP
		Vector {-1, 0}, // LEFT
		Vector {0, 1}, // DOWN
		Vector {1, 0}, // RIGHT
	};

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

bool MazePlayer::Cango(Vector pos)
{
	Block::BlockType type = _maze.lock()->GetBlockType(pos);
	if(type == Block::BlockType::DISABLE)
		return false;
	return true;
}
