#include "stdafx.h"
#define ENSPEED 3.0f
#define ENHEALTH 600.0f

void Enemy::Init(int num)
{
	switch (num)
	{
	case 0:
		type = SPEED;
		speed = ENSPEED;
		hp = ENHEALTH /2;
		frameX = 6;
		frameY = 0;
		break;
	case 1:
		type = HEALTH;
		speed = (ENSPEED / 2);
		hp = ENHEALTH;
		frameX = 6;
		frameY = 1;
		break;
	case 2:
		type = BALANCE;
		speed = (ENSPEED / 4)*3;
		hp = ENHEALTH/ 2;
		frameX = 6;
		frameY = 2;
		break;
	case 3:
		type = BONUS;
		speed = ENSPEED/2;
		hp = ENHEALTH /5;
		frameX = 6;
		frameY = 3;
		break;
	case 4:
		type = HEALTH2;
		speed = (ENSPEED / 2);
		hp = ENHEALTH*2;
		frameX = 1;
		frameY = 4;
		break;
	case 5:
		type = BALANCE2;
		speed = (ENSPEED / 4) * 3;
		hp = (ENHEALTH/2)*3;
		frameX = 3;
		frameY = 4;
		break;
	default:
		break;
	}
	image = IMAGEMANAGER->FindImage("enemy");
	isGamed = false;
	position = 0;
}

void Enemy::Update()
{
}

void Enemy::Move()
{
	if (isAlive)
	{
		float angle;
		angle = GetAngle(pos, nextPos);
		pos.x += cosf(angle)*speed;
		pos.y += -sinf(angle)*speed;
	}
}

void Enemy::Render(HDC hdc)
{
	if (isAlive)
	{
		image->Render(hdc, pos.x - image->GetFrameW() / 2, pos.y - image->GetFrameH() / 2, frameX, frameY);
	}
}

void Enemy::DOA(HDC hdc)
{
	if (isAlive)
	{
		if (hp < 1.0f)
		{
			isAlive = false;
			for (int i = 255; i < 0; i--)
			{
				image->AlphaRender(hdc, pos.x - image->GetFrameW() / 2, pos.y - image->GetFrameH() / 2, frameX, frameY, i);
			}
		}
	}
}

void Enemy::Upgrade(float dif)
{
	speed += speed * dif;
	hp += hp * dif;
	if (speed > 30.0f)
	{
		speed = 30.0f;
	}
}
