#pragma once

class BackBuffer
{
private:
	HDC hMemDC;
	HBITMAP hBit, hOldBit;
	int widht;
	int height;

public:
	BackBuffer();
	void Init(int _widht, int _height);
	void Release();
	void Render(HDC hdc);

	inline HDC GetMemDC() { return hMemDC; }
};