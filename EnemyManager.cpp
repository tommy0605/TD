#include "stdafx.h"

EnemyManager::EnemyManager()
{
	dif = 0.5f;
	count = 0;
}

void EnemyManager::Init(MapTool * map)
{
	mapt = map;
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
	for (int i = 0; i < enemyList.size(); i++)
	{
		count++;
		if (!enemyList[i]->GetIsGamed())
		{
			if (count > 3)
			{
				count -= 3;
				enemyList[i]->SetAlive(true);
				enemyList[i]->SetGamed(true);
			}
		}
	}

}

void EnemyManager::Move(Enemy * enemy)
{
	if (enemy->GetIsAlive())
	{
		
	}
}
