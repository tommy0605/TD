#include "stdafx.h"
#include "MapTool.h"

void MapTool::Init()
{
	SetTile();
	
	currentTile = new Tile;
	for (int i = 0; i < 4; i++)
	{
		sampleTile[i] = new Tile;
		sampleTile[i]->Init(60-i, 0);
	}
	sampleTile[0]->color = RGB(0, 0, 0);
	sampleTile[0]->isOpen = false;
	sampleTile[0]->attribute = WALL;
	sampleTile[1]->color = RGB(80, 80, 80);
	sampleTile[1]->isOpen = true;
	sampleTile[1]->attribute = NONE_TILE;
	sampleTile[2]->color = RGB(0, 128, 255);
	sampleTile[2]->isOpen = true;
	sampleTile[2]->attribute = START;
	sampleTile[3]->color = RGB(255, 30, 255);
	sampleTile[3]->isOpen = true;
	sampleTile[3]->attribute = END;
	curTile = new Tile;
	curTile = sampleTile[1];
}

void MapTool::Update()
{
	//if (KEYMANAGER->isOnceKeyDown(VK_F1))
		//SaveMap();
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		LoadMap();
		SetSE();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
		SCENEMANAGER->ChangeScene("game");
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

void MapTool::Render(HDC hdc)
{
	HBRUSH hBrush, hOldBrush;
	hBrush = CreateSolidBrush(RGB(30, 30, 30));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, 0, 0, WINWIDTH, WINHEIGHT);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);
	DeleteObject(hOldBrush);
	TotalRender(hdc);
	
	for (int i = 0; i < 4; i++)
	{
		sampleTile[i]->Render(hdc);
	}

}

void MapTool::Release()
{
}

void MapTool::SetTile()
{
	startTile = new Tile;
	endTile = new Tile;

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
			node->color = RGB(80, 80, 80);
			totalList.push_back(node);
		}
	}
}

void MapTool::TotalRender(HDC hdc)
{
	for (int i = 0; i < totalList.size(); i++)
	{
		totalList[i]->Render(hdc);
	}
}

void MapTool::SetSE()
{
	for (int i = 0; totalList.size(); i++)
	{
		if (totalList[i]->attribute == START)
		{
			startTile = totalList[i];
			break;
		}
	}

	for (int i = 0; totalList.size(); i++)
	{
		if (totalList[i]->attribute == END)
		{
			endTile = totalList[i];
			break;
		}
	}
	currentTile = startTile;
}

void MapTool::AddOpenList()
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

void MapTool::SaveMap()
{
	Tile tile[TILEX*TILEY];
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			tile[i*TILEX + j] = *totalList[i*TILEX + j];
		}
	}

	HANDLE file;
	DWORD write;

	file = CreateFile(L"mapData.map", GENERIC_WRITE, NULL, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, tile, sizeof(Tile) * TILEX * TILEY, &write, NULL);

	CloseHandle(file);
}

void MapTool::LoadMap()
{
	Tile tile[TILEX*TILEY];

	HANDLE file;
	DWORD read;

	file = CreateFile(L"mapData.map", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, tile, sizeof(Tile)*TILEX*TILEY, &read, NULL);

	CloseHandle(file);
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			*totalList[i*TILEX + j] = tile[i*TILEX + j];
		}
	}
}

void MapTool::PathFinder()
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

void MapTool::SetWall()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 4; i++)
		{
			if (PtInRect(&sampleTile[i]->rc, mousePos))
			{
				curTile = sampleTile[i];
				break;
			}
		}
		for (int i = 0; i < totalList.size(); i++)
		{
			if (PtInRect(&totalList[i]->rc, mousePos))
			{
				totalList[i]->color = curTile->color;
				totalList[i]->isOpen = curTile->isOpen;
				totalList[i]->attribute = curTile->attribute;
			}
		}
	}
}

RECT MapTool::GetMouseRect()
{
	for (int i = 0; i < totalList.size(); i++)
	{
		if (PtInRect(&totalList[i]->rc, mousePos))
		{
			return totalList[i]->rc;
		}
	}
	return RECT();
}
