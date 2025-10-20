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

	CreateMaze();
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

void Maze::CreateMaze()
{
	// 노드 뚫기
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::BlockType::DISABLE);
			}
			else
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
			}
		}
	}

	// 노드 입장에서 오른쪽 혹은 아래쪽 뚫기
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			// 시작점
			if (x == 1 && y == 1)
			{
				_blocks[y][x]->SetType(Block::ABLE);
			}

			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			// 해당 노드 입장
			// 끝점 처리
			if (y == MAX_Y - 2 && x == MAX_X - 2)
			{
				_blocks[y][x]->SetType(Block::ABLE);
				continue;
			}

			// 맨 아랫줄 다 뚫기
			if (y == MAX_Y - 2)
			{
				_blocks[y][x + 1]->SetType(Block::ABLE);
				continue;
			}

			// 맨 오른쪽줄 다 뚫기
			if (x == MAX_Y - 2)
			{
				_blocks[y + 1][x]->SetType(Block::ABLE);
				continue;
			}

			// 노드 입장에서 오른쪽 혹은 아래쪽 뚫기
			int randValue = rand() % 2;

			if(randValue == 0)
				_blocks[y][x+1]->SetType(Block::ABLE);
			else
				_blocks[y+1][x]->SetType(Block::ABLE);
		}
	}
}
