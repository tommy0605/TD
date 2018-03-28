#pragma once
//A* �˰��� : ��� ���������� ���� ��ǥ ����������
//���� �ִ� ��θ� ã�Ƴ��� �˰���
//f(n) : �ִ� ���
//g(n) : ��� ������ ���� ������ ������ ��� ����ġ
//h(n) : ������ n���� ���� ��ǥ ������ ������ ���� ��� ����ġ
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