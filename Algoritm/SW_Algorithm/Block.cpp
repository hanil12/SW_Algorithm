#include "framework.h"
#include "Block.h"

Block::Block()
{
	_rect = make_shared<Rect>(0,0,0,0);
	
	_pens.push_back(CreatePen(1,2,RGB(255,0,0)));
	_pens.push_back(CreatePen(1,2,RGB(0,255,0)));
	_pens.push_back(CreatePen(1,2,RGB(0,0,255)));

	_brushes.push_back(CreateSolidBrush(RGB(255,0,0)));
	_brushes.push_back(CreateSolidBrush(RGB(0,255,0)));
	_brushes.push_back(CreateSolidBrush(RGB(0,255,255)));
}

Block::~Block()
{
	for(auto& pen : _pens)
		DeleteObject(pen);

	for(auto& brush : _brushes)
		DeleteObject(brush);
}

void Block::Update()
{
	_rect->Update();
}

void Block::Render(HDC hdc)
{
	SelectObject(hdc,_pens[_type]);
	SelectObject(hdc, _brushes[_type]);

	_rect->Render(hdc);
}

void Block::SetSize(Vector v)
{
	_rect->_size = v;
}

void Block::SetCenter(Vector v)
{
	_rect->_center = v;
}
