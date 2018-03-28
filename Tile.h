#pragma once
//A* 알고리즘 : 출발 꼭짓점에서 부터 목표 꼭짓점까지
//가는 최단 경로를 찾아내는 알고리즘
//f(n) : 최단 경로
//g(n) : 출발 꼭짓점 부터 꼭짓점 까지의 경로 가중치
//h(n) : 꼭짓점 n으로 부터 목표 꼭짓점 까지의 추정 결로 가중치
//f(n) = g(n) + h(n)

#define TILESIZE 10

#define TILEX (WINWIDTH / TILESIZE)
#define TILEY (WINHEIGHT / TILESIZE)

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