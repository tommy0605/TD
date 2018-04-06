#include "stdafx.h"
#include "Bullet.h"

void BulletManager::Init(string imageName, int maxCount)
{
	for (int i = 0; i < maxCount; i++)
	{
		Bullet* bullet;
		bullet = new Bullet;
		bullet->image = IMAGEMANAGER->FindImage(imageName);
		bullet->isFire = false;
		bulletList.push_back(bullet);
	}
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
	for (Bullet *b : bulletList)
	{
		b->Render(hdc);
	}
}

void BulletManager::Fire(POINT pos, float angle, float speed)
{
	for (int i = 0; i < bulletList.size(); i++)
	{
		if (!bulletList[i]->isFire)
		{
			bulletList[i]->isFire = true;
			bulletList[i]->rc.left = pos.x;
			bulletList[i]->rc.top = pos.y;
			bulletList[i]->angle = angle;
			bulletList[i]->speed = speed;
			break;
		}
	}
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