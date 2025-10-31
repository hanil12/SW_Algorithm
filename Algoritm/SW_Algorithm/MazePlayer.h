#pragma once
class MazePlayer
{
	enum Dir
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,
		UPLEFT,
		UPRIGHT,
		DOWNLEFT,
		DOWNRIGHT,

		DIR_COUNT = 8
	};

	Vector frontPos[8] =
	{
		Vector {0, -1}, // UP
		Vector {-1, 0}, // LEFT
		Vector {0, 1}, // DOWN
		Vector {1, 0}, // RIGHT

		Vector {-1, -1}, // UPLEFT
		Vector {1, -1}, // UPRIGHT
		Vector {-1, 1}, // DOWNLEFT
		Vector {1, 1}, // DOWNRIGHT
	};

	struct Vertex_Djikstra
	{
		Vector v;
		int cost; // g

		bool operator<(const Vertex_Djikstra& other) const
		{
			if(cost < other.cost)
				return true;
			return false;
		}

		bool operator>(const Vertex_Djikstra& other) const
		{
			if(cost > other.cost)
				return true;
			return false;
		}
	};

	struct Vertex
	{
		Vector v;
		int g;
		int h; // 휴리스틱함수(맨하탄거리공식) 결과값
		int f;

		bool operator<(const Vertex& other) const
		{
			if (f < other.f)
				return true;
			return false;
		}

		bool operator>(const Vertex& other) const
		{
			if (f > other.f)
				return true;
			return false;
		}
	};

public:
	MazePlayer(shared_ptr<Maze> maze);
	~MazePlayer();

	void Update();
	void RightHand();
	void DFS_Method(); // 길찾기에 최적화되어있지 않음.
	void BFS_Method();
	void Djikstra(Vertex_Djikstra start);
	void AStar(Vertex start, Vertex end);

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

