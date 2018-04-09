#include "stdafx.h"

void Tower::Init(string name, float hp, BUILDNAME bname, int frameX, int frameY, int disFrameX, int disFrameY, float bulSpeed, float fireR, float rangee, int bulletSize, COLORREF bcc)
{
	bm = new BulletManager;
	pos.x = 9999;
	pos.y = 9999;
	bName = name;
	this->hp = hp;
	maxHp = hp;
	buildName = bname;
	fX = frameX;
	fY = frameY;
	dFX = disFrameX;
	dFY = disFrameY;
	fireRate = fireR;
	count = 0;
	range = rangee;
	bm->Init(bulletSize, bcc);
	bulletSpeed = bulSpeed;
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
	image->RenderSize(hdc, posx, posy, fX, fY, 30, 30);
}

void Tower::Attack(float angle)
{
	POINT pos;
	pos.x = rc.left;
	pos.y = rc.top;
	bm->Fire(pos, angle, bulletSpeed);
	
}

