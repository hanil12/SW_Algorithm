#include "framework.h"
#include "Rect.h"

Rect::Rect(int left, int top, int right, int bottom)
{
	_center.x = (left + right) * 0.5f;
	_center.y = (top + bottom) * 0.5f;

	_size.x = (right - left);
	_size.y = (bottom - top);
}

Rect::Rect(Vector center, Vector size)
: _center(center)
, _size(size)
{
}

void Rect::Update()
{
}

void Rect::Render(HDC hdc)
{
	float left = _center.x - _size.x * 0.5f;
	float right = _center.x + _size.x * 0.5f;
	float top = _center.y - _size.y * 0.5f;
	float bottom = _center.y + _size.y * 0.5f;

	Rectangle(hdc, left, top, right, bottom);
}
