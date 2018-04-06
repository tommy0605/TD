#pragma once

#define TILESIZE 15

#define TILEX (TWINWIDTH / TILESIZE)
#define TILEY (TWINHEIGHT / TILESIZE)

enum STATE
{
	NONE_TILE,
	START,
	END,
	WALL
};

struct Tile
{
	int idX, idY;

	POINT center;
	RECT rc;

	float totalCost;	//f(n) : �� ���
	float costFromStart;//g(n) : ����� ���� ������ ������ ���
	float costToGoal;	//h(n) : ������ ���� ������ ������ ���

	bool isOpen;

	Tile* parentNode;

	COLORREF color;
	HBRUSH hBrush;
	HPEN hPen;

	STATE attribute;

	Tile();
	~Tile();

	void Init(int x, int y);
	void Render(HDC hdc);
};