#pragma once
class Block
{
public:
	enum BlockType
	{
		DISABLE = 0,
	};

	Block();
	~Block();

	void Update();
	void Render(HDC hdc);

	void SetSize(Vector v);
	void SetCenter(Vector v);

	Vector Center() { return _rect->_center; }
	Vector Size() { return _rect->_size; }

private:
	BlockType _type = BlockType::DISABLE;

	shared_ptr<Rect> _rect;

	vector<HPEN> _pens;
	vector<HBRUSH> _brushes;
};

