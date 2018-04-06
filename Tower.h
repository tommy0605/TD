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
private:
	string bName;
	Image* image;
	int fX;
	int fY;
	int dFX;
	int dFY;
	float hp;
	float maxHp;
	BUILDNAME buildName;
	
public:
	//TODO: 공격, 맞는거 처리
	void Init(string name, float hp, BUILDNAME bname);
	void Render(HDC hdc);
	void RenderMap(HDC hdc);
	
	Image* GetImage() { return image; }
	float* GetHp() { return &hp; }
	BUILDNAME GetBE() { return buildName; }
};