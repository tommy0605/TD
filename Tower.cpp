#include "stdafx.h"

void Tower::Init(string name, float hp, BUILDNAME bname, int frameX, int frameY, int disFrameX, int disFrameY, float bulSpeed, float fireR, float rangee, int bulletSize, COLORREF bcc, float damage)
{
	bm = new BulletManager;
	pos.x = 9000;
	pos.y = 9000;

	rc.left = pos.x + 1;
	rc.top = pos.y + 1;
	rc.right = pos.x + 28;
	rc.bottom = pos.x + 28;
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
	this->damage = damage;
	bm->Init(30, bcc, damage);
	bulletSpeed = bulSpeed;
	image = IMAGEMANAGER->FindImage("td");
}

void Tower::Render(HDC hdc, int posx, int posy)
{
	image->Render(hdc, posx, posy, fX, fY);
}

void Tower::Update()
{
	bm->Update(range);
}

void Tower::BulletRender(HDC hdc)
{
	bm->Render(hdc);
}

void Tower::DisRender(HDC hdc, int posx, int posy)
{
	image->Render(hdc, posx, posy, dFX, dFY);
}

void Tower::GameRender(HDC hdc, int posx, int posy)
{
	pos.x = posx;
	pos.y = posy;
	rc.left = posx + 1;
	rc.top = posy + 1;
	rc.right = posx + 28;
	rc.bottom = posy + 28;
	image->RenderSize(hdc, posx, posy, fX, fY, 28, 28);
}

void Tower::Attack(float angle)
{
	POINT pos;
	pos.x = rc.left;
	pos.y = rc.top;
	count++;
	if (count > fireRate)
	{
		bm->Fire(pos, angle, bulletSpeed, damage);
		count = 0;
	}
	//bm->Fire(pos, angle, bulletSpeed, damage);
}

bool Tower::CheckEnemy(POINT pos)
{
	if (IsPointInCircle(pos, range, this->pos))
	{
		Attack(GetAngle(this->pos, pos));
		return true;
	}
	return false;
}

