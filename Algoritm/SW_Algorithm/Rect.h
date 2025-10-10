#pragma once
class Rect
{
public:
// Rectangle(hdc, left, top, right, bottom)
	Rect(int left, int top, int right, int bottom);
	Rect(Vector center, Vector size);
	~Rect() = default;

	void Update();
	void Render(HDC hdc);

public:
	Vector _center;
	Vector _size;
};

