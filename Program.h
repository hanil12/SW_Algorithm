#pragma once
class Program
{
public:
	Program(HWND hWnd);
	~Program();

	void Update();
	void Render(HDC hdc);

	static HDC _backBuffer;

private:
	shared_ptr<Maze> _maze;

	HBITMAP _hBit;
};

