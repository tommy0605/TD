#include "stdafx.h"

void Tower::Init(string name, float hp, BUILDNAME bname, int frameX, int frameY, int disFrameX, int disFrameY)
{
	bName = name;
	this->hp = hp;
	maxHp = hp;
	buildName = bname;
	fX = frameX;
	fY = frameY;
	dFX = disFrameX;
	dFY = disFrameY;
	image = IMAGEMANAGER->FindImage("td");
}

void Tower::Render(HDC hdc, int posx, int posy)
{
	image->Render(hdc, posx, posy, fX, fY);
}

void Tower::DisRender(HDC hdc, int posx, int posy)
{
	image->Render(hdc, posx, posy, dFX, dFY);
}

void Tower::GameRender(HDC hdc, int posx, int posy)
{
	image->RenderSize(hdc, posx, posy, 30, 30);
}

