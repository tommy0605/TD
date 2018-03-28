#include "stdafx.h"

Tile::Tile()
{
	totalCost = 0;
	costFromStart = 0;
	costToGoal = 0;

	parentNode = NULL;
	idX = idY = 0;
	attribute = NONE_TILE;
	isOpen = true;
}

Tile::~Tile()
{
	DeleteObject(hPen);
}

void Tile::Init(int x, int y)
{
	color = RGB(255, 255, 255);
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));

	center.x = x * TILESIZE + TILESIZE / 2;
	center.y = y * TILESIZE + TILESIZE / 2;

	idX = x;
	idY = y;

	rc = RectMakeCenter(center.x, center.y,
		TILESIZE, TILESIZE);
}

void Tile::Render(HDC hdc)
{
	hBrush = CreateSolidBrush(color);

	SelectObject(hdc, hBrush);
	FillRect(hdc, &rc, hBrush);
	SelectObject(hdc, hPen);
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	DeleteObject(hBrush);
}
