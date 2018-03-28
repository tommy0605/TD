#include "stdafx.h"

BackBuffer::BackBuffer()
{
	hMemDC = NULL;
	hBit = NULL;
	hOldBit = NULL;
	widht = 0;
	height = 0;
}

void BackBuffer::Init(int _widht, int _height)
{
	HDC hdc = GetDC(hWnd);

	hMemDC = CreateCompatibleDC(hdc);
	hBit = CreateCompatibleBitmap(hdc, _widht, _height);
	hOldBit = (HBITMAP)SelectObject(hMemDC, hBit);
	widht = _widht;
	height = _height;

	ReleaseDC(hWnd, hdc);
}

void BackBuffer::Release()
{
	SelectObject(hMemDC, hOldBit);
	DeleteObject(hBit);
	DeleteDC(hMemDC);
}

void BackBuffer::Render(HDC hdc)
{
	BitBlt(hdc, 0, 0, widht, height, hMemDC, 0, 0, SRCCOPY);
}
