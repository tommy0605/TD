#include "stdafx.h"

void GameScene::Init()
{	
	SetTile();
}

void GameScene::Update()
{
	SetWall();

	if (isStart)
	{
		count++;
		if (count > 5)
		{
			PathFinder();
			count = 0;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		isStart = true;
	}
}

void GameScene::Render(HDC hdc)
{
	for (int i = 0; i < totalList.size(); i++)
	{
		totalList[i]->Render(hdc);
	}
}

void GameScene::Release()
{
}

void GameScene::SetTile()
{
	startTile = new Tile;
	startTile->Init(4, 12);
	startTile->attribute = START;

	endTile = new Tile;
	endTile->Init(30, 12);
	endTile->attribute = END;

	currentTile = startTile;

	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			if (j == startTile->idX && i == startTile->idY)
			{
				startTile->color = RGB(0, 128, 255);
				totalList.push_back(startTile);
				continue;
			}
			if (j == endTile->idX && i == endTile->idY)
			{
				endTile->color = RGB(255, 30, 255);
				totalList.push_back(endTile);
				continue;
			}

			Tile* node = new Tile;
			node->Init(j, i);
			totalList.push_back(node);
		}
	}
}

void GameScene::AddOpenList()
{
	int startX = currentTile->idX - 1;
	int startY = currentTile->idY - 1;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int vecIndex = (startY * TILEX) +
				startX + j + (i*TILEX);

			if (vecIndex > totalList.size() - 1)
				break;

			Tile* node = totalList[vecIndex];

			if (!node->isOpen)
				continue;
			if (node->attribute == START)
				continue;

			node->parentNode = currentTile;

			bool isAlreadyAddedTile = false;

			for (it = openList.begin(); it != openList.end(); it++)
			{
				if (*it == node)
				{
					isAlreadyAddedTile = true;
					break;
				}
			}

			if (node->attribute != END)
				node->color = RGB(128, 240, 255);
			if (!isAlreadyAddedTile)
				openList.push_back(node);
		}
	}
}

void GameScene::PathFinder()
{
	float tempTotalCost = 5000.0f;
	Tile* tempTile = NULL;

	AddOpenList();

	if (openList.size() == 0)
	{
		MessageBox(hWnd, L"길이 막혔습니다.", L"Error", MB_OK);
		isStart = false;
		return;
	}

	for (int i = 0; i < openList.size(); i++)
	{
		//h(n) 구하기
		openList[i]->costToGoal =
			(abs(endTile->idX - openList[i]->idX) +
				abs(endTile->idY - openList[i]->idY)) * 10;

		//g(n) 구하기
		POINT center1 = openList[i]->parentNode->center;
		POINT center2 = openList[i]->center;

		openList[i]->costFromStart =
			(GetDistance(center1, center2) > TILESIZE ? 14 : 10);

		openList[i]->totalCost =
			openList[i]->costToGoal + openList[i]->costFromStart;

		if (tempTotalCost > openList[i]->totalCost)
		{
			tempTotalCost = openList[i]->totalCost;
			tempTile = openList[i];
		}

		bool isAlreadyAddedTile = false;

		for (it = openList.begin(); it != openList.end(); it++)
		{
			if (*it == tempTile)
			{
				isAlreadyAddedTile = true;
				break;
			}
		}

		openList[i]->isOpen = false;
		if (isAlreadyAddedTile)
			continue;
		openList.push_back(tempTile);
	}

	if (tempTile->attribute == END)
	{
		while (currentTile->parentNode != NULL)
		{
			currentTile->color = RGB(255, 0, 128);
			currentTile = currentTile->parentNode;
		}
		isStart = false;
		return;
	}

	closeList.push_back(tempTile);
	for (it = openList.begin(); it != openList.end(); it++)
	{
		if (*it == tempTile)
		{
			it = openList.erase(it);
			break;
		}
	}
	currentTile = tempTile;
}

void GameScene::SetWall()
{
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < totalList.size(); i++)
		{
			if (PtInRect(&totalList[i]->rc, mousePos))
			{
				if (totalList[i]->isOpen &&
					totalList[i]->attribute == NONE_TILE)
				{
					totalList[i]->isOpen = false;
					totalList[i]->attribute = WALL;
					totalList[i]->color = RGB(128, 128, 128);
					break;
				}
			}
		}
	}
}
