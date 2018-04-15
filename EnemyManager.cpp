#include "stdafx.h"

EnemyManager::EnemyManager()
{
	dif = 0.5f;
	count = 0;
}

void EnemyManager::Init(MapTool * map)
{
	mapt = map;
	closeList = mapt->GetCloseList();
	int randNum;
	for (int i = 0; i < dif * 100; i++)
	{
		Enemy* enemy = new Enemy;
		randNum = rand() % 1000;
		if (randNum > 750 + dif)
			enemy->Init(0);
		if (randNum <= 750 + dif && randNum > 500 + dif)
			enemy->Init(1);
		if (randNum <= 500 + dif && randNum > 250 + dif)
			enemy->Init(2);
		if (randNum <= 250 + dif && randNum > 0 + dif)
			enemy->Init(3);
		if (randNum <= dif && randNum > dif/2)
			enemy->Init(4);
		if (randNum <= dif/2 && randNum > 0)
			enemy->Init(5);
		enemy->SetPos(GetRectCenterPos(map->GetStartTileRect()));
		//enemy->SetNextPos(closeList[1]->center);
		enemyList.push_back(enemy);
	}
}

void EnemyManager::Render(HDC hdc)
{
	for (int i = 0; i < enemyList.size(); i++)
	{
		if (enemyList[i]->GetIsGamed())
		{
			if (enemyList[i]->GetIsAlive())
			{
				enemyList[i]->Render(hdc);
				enemyList[i]->DOA(hdc);
			}
		}
	}
}

void EnemyManager::Update()
{
	closeList = mapt->GetCloseList();
	for (int i = 0; i < enemyList.size(); i++)
	{
		count++;
		if (enemyList[i]->GetIsGamed() == false)
		{
			enemyList[i]->SetAlive(true);
			enemyList[i]->SetGamed(true);
			if (count > 10)
			{
				count = 0;
				return;
			}
		}
		else
		{
			enemyList[i]->Move();
			Move();
		}
	}
}

void EnemyManager::Move()
{	
	for (int i = 0; i < enemyList.size(); i++)
	{
		if (enemyList[i]->GetIsAlive())
		{
			if (enemyList[i]->GetCurPos() >= closeList.size() - 1)
			{
				
			}
			else
			{
				enemyList[i]->SetNextPos(closeList[enemyList[i]->GetCurPos() + 1]->center);
				if (((enemyList[i]->GetPos().x >= closeList[enemyList[i]->GetCurPos() + 1]->center.x-5) && (enemyList[i]->GetPos().x <= closeList[enemyList[i]->GetCurPos() + 1]->center.x +5)) && ((enemyList[i]->GetPos().y >= closeList[enemyList[i]->GetCurPos() + 1]->center.y - 5) && (enemyList[i]->GetPos().y <= closeList[enemyList[i]->GetCurPos() + 1]->center.y + 5)))
				{
					enemyList[i]->SetCurPos(enemyList[i]->GetCurPos() + 1);
				}
			}
		}
	}
	
}
