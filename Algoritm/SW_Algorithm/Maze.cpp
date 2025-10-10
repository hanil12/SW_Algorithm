#include "framework.h"
#include "Maze.h"

Maze::Maze()
{
	_blocks.resize(MAX_Y);

	Vector offset = Vector(380,200);

	for (int y = 0; y < MAX_Y; y++)
	{
		_blocks[y].reserve(MAX_X);
		for (int x = 0; x < MAX_X; x++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			block->SetCenter(Vector(18*x, 18*y) + offset);
			block->SetSize(Vector(13,13));
			_blocks[y].push_back(block);
		}
	}
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
		{
			block->Update();
			block->SetCenter(block->Center());
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
			block->Render(hdc);
	}
}
