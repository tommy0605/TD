#include "stdafx.h"

Tank::Tank()
{
	image = IMAGEMANAGER->AddImage("tank", L"Image/tank.bmp", 256, 128, 8, 4,
		true, RGB(255, 0, 255));
	pos.x = TILESIZE;
	pos.y = TILESIZE;

	speed = 5;
}

void Tank::Update()
{
	Move();
}

void Tank::Render(HDC hdc)
{
	image->Render(hdc, pos.x, pos.y, image->GetFrameX(), image->GetFrameY());
}

void Tank::Move()
{
	POINT dirPos = pos;

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		pos.x += speed;
		image->SetFrameY(2);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		pos.x -= speed;
		image->SetFrameY(3);		
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		pos.y -= speed;
		image->SetFrameY(0);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		pos.y += speed;
		image->SetFrameY(1);
	}

	CollisionCheck();
	
}

POINT Tank::GetTilePos(POINT pos)
{
	//탱크 RECT를 만들어서
	//충돌 했을 경우(IntersectRect)
	//상하좌우 충돌 판단해서
	//겹치는 영역 만큼 빼주 거나 더해줘서
	//안겹치게 만드는 방법

	POINT tilePos = {};
	Tile* tile;
	tile = tankMap->GetTile();
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&tile[i].rc, pos))
		{			
			tilePos.x = tile[i].frameX;
			tilePos.y = tile[i].frameY;
		}
	}

	return tilePos;
}

bool Tank::IsWator(POINT pos)
{	
	if (pos.x == 4 && pos.y == 0)
	{		
		return true;
	}
	else if (pos.x == 0 && pos.y == 3)
	{
		return true;
	}

	return false;
}

RECT Tank::GetRect()
{
	RECT rc = { pos.x, pos.y,
		pos.x + image->GetFrameW(),
		pos.y + image->GetFrameH() };
	return rc;
}

bool Tank::IsWator2(POINT pos)
{
	POINT tilePos = {};
	Tile* tile;
	tile = tankMap->GetTile();
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&tile[i].rc, pos))
		{
			tilePos.x = tile[i].frameX;
			tilePos.y = tile[i].frameY;



			if (IsWator(tilePos))
			{
				RECT pRect = GetRect();
				GetCollisionReposition(&pRect, &tile[i].rc);
				pos.x = pRect.left;
				pos.y = pRect.top;
				return true;
			}
		}
	}

	return false;
}

void Tank::CollisionCheck()
{
	RECT pRect = GetRect();

	Tile* tile;
	tile = tankMap->GetTile();

	for (int i = 0; i < TILEX*TILEY; i++)
	{
		POINT frame = { tile[i].frameX, tile[i].frameY };
		if (IsWator(frame))
		{
			GetCollisionReposition(&pRect, &tile[i].rc);
			pos.x = pRect.left;
			pos.y = pRect.top;
		}
	}
}
