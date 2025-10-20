#pragma once

#define MAX_X 25
#define MAX_Y 25

class Maze
{
public:
	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMaze();
	void SetBlock(Vector v, Block::BlockType type) { _blocks[v.y][v.x]->SetType(type); }
	Block::BlockType GetBlockType(Vector v) { return _blocks[v.y][v.x]->GetType(); }

	Vector StartPos() { return {1,1}; }
	Vector EndPos() { return { MAX_X - 2, MAX_Y - 2}; }

private:
	vector<vector<shared_ptr<Block>>> _blocks;
	int temp;
};

