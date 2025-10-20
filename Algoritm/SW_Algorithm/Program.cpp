#include "framework.h"
#include "program.h"

#include "MazeScene.h"

HDC Program::_backBuffer = nullptr;

Program::Program(HWND hWnd)
{
	_scene = make_shared<MazeScene>();

	HDC hdc = GetDC(hWnd);
	_backBuffer = CreateCompatibleDC(hdc);
	_hBit = CreateCompatibleBitmap(hdc,1200,800);
	SelectObject(_backBuffer, _hBit);
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(_backBuffer, 0,0,1200,800,BLACKNESS); // backbuffer 지우기

	_scene->Render(_backBuffer); // backbuffer에 그림 그리기

	// backbuffer의 그림을 복사해오기
	BitBlt(
		hdc,
		0,0,
		1200, 800,
		_backBuffer
		,0,0,
		SRCCOPY
	);
}
