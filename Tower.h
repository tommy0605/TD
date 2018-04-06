#pragma once

enum BUILDNAME
{
	BASE,
	LONE,
	LONEDIS,
	LTWO,
	LTWODIS,
	LTHR,
	LTHRDIS,
	DRLONE,
	DRLONEDIS,
	DRLTWO,
	DRLTWODIS,
	DRLTHR,
	DRLTHRDIS,
	SPLONE,
	SPLONEDIS,
	SPLTWO,
	SPLTWODIS,
	SPLTHR,
	SPLTHRDIS,
	SNPONE,
	SNPONEDIS,
	SNPTWO,
	SNPTWODIS,
	RNGUP,
	DMGUP,
	MONEYUP,
	SCIENCE
};


class Tower
{
public:
	string bName;
	int fX;
	int fY;
	int dFX;
	int dFY;
	float hp;
	float maxHp;
	Image* image;
	RECT rc;
	BUILDNAME buildName;

	//TODO: ����, �´°� ó��
	void Init(string name, float hp, BUILDNAME bname, int frameX, int frameY, int disFrameX, int disFrameY);
	void Render(HDC hdc, int posx, int posy);
	void DisRender(HDC hdc, int posx, int posy);
	void GameRender(HDC hdc, int posx, int posy);
};