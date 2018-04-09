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


struct Tower
{
	string bName;
	int fX;
	int fY;
	int dFX;
	int dFY;
	float hp;
	float maxHp;
	float fireRate;
	float bulletSpeed;
	float range;
	POINT pos;
	Image* image;
	RECT rc;
	BUILDNAME buildName;
	BulletManager* bm;
	float count;
	//TODO: 공격, 맞는거 처리
	void Init(string name, float hp, BUILDNAME bname, int frameX, int frameY, int disFrameX, int disFrameY, float bulSpeed, float fireR, float rangee, int bulletSize, COLORREF bcc);
	void Render(HDC hdc, int posx, int posy);
	void DisRender(HDC hdc, int posx, int posy);
	void GameRender(HDC hdc, int posx, int posy);
	void Attack(float angle);
};