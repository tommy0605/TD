#include "stdafx.h"
#include "Bullet.h"

void BulletManager::Init(int size, COLORREF bcc, float damage)
{
	for (int i = 0; i < 5; i++)
	{
		Bullet* bullet;
		bullet = new Bullet;
		bullet->size = size;
		bullet->damage = damage;
		bullet->isFire = false;
		bulletList.push_back(bullet);
	}
	bc = bcc;
}

void BulletManager::Update()
{
	for (Bullet* b : bulletList)
	{
		b->Move();
		if (b->rc.left < 0) b->isFire = false;
	}
}

void BulletManager::Render(HDC hdc)
{
	//HBRUSH hOldBrush;
	//hOldBrush = (HBRUSH)SelectObject(hdc, CreateSolidBrush(bc));
	for (Bullet *b : bulletList)
	{
		b->Render(hdc);
	}
	//SelectObject(hdc, hOldBrush);
	//DeleteObject(hOldBrush);
}

void BulletManager::Fire(POINT pos, float angle, float speed, float damage)
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		if (!bulletList[i]->isFire)
		{
			bulletList[i]->isFire = true;
			bulletList[i]->damage = damage;
			bulletList[i]->rc.left = pos.x;
			bulletList[i]->rc.top = pos.y;
			bulletList[i]->angle = angle;
			bulletList[i]->speed = speed;
			return;
		}
	}
	Bullet* bullet;
	bullet = new Bullet;
	bullet->size = bullet[1].size;
	bullet->isFire = true;
	bullet->damage = damage;
	bullet->rc.left = pos.x;
	bullet->rc.top = pos.y;
	bullet->angle = angle;
	bullet->speed = speed;
	bulletList.push_back(bullet);
}

bool BulletManager::IsCollision(RECT rc)
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		RECT cRect;
		if (bulletList[i]->isFire)
		{
			if (IntersectRect(&cRect, &bulletList[i]->rc, &rc))
			{
				bulletList[i]->isFire = false;
				return true;
			}
		}

	}
	return false;
}
