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

public:
	MazePlayer(shared_ptr<Maze> maze);
	~MazePlayer();

	void Update();
	void RightHand();
	bool Cango(Vector pos);

private:
	vector<Vector> _path;
	int _pathIndex = 0;
	float _time = 0.0f;
	Vector _pos;

	weak_ptr<Maze> _maze;
	Dir _dir;
};

