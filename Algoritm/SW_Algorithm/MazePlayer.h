#pragma once
class MazePlayer
{
	enum Dir
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,

		DIR_COUNT = 4
	};

	Vector frontPos[4] =
	{
		Vector {0, -1}, // UP
		Vector {-1, 0}, // LEFT
		Vector {0, 1}, // DOWN
		Vector {1, 0}, // RIGHT
	};

public:
	MazePlayer(shared_ptr<Maze> maze);
	~MazePlayer();

	void Update();
	void RightHand();
	void DFS_Method(); // 길찾기에 최적화되어있지 않음.
	void BFS_Method();
	bool Cango(Vector pos);

private:
	void DFS(Vector here, vector<vector<bool>>& visited, shared_ptr<Maze> maze);

private:
	vector<Vector> _path;
	int _pathIndex = 0;
	float _time = 0.0f;
	Vector _pos;

	weak_ptr<Maze> _maze;
	Dir _dir;
};

