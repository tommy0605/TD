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

	float totalCost;	//f(n) : 총 비용
	float costFromStart;//g(n) : 출발점 부터 꼭짓점 까지의 비용
	float costToGoal;	//h(n) : 꼭짓점 부터 도착점 까지의 비용

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