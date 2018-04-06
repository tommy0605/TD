#include "stdafx.h"

void GameScene::Init()
{
	curTower = new Tower;

	mouseRC = RectMake(mousePos.x, mousePos.y, 20, 20);
	bm = new BuildingManager;
	bm->Init();
	map = new MapTool;
	map->SetTile();
	map->LoadMap();
	map->SetSE();
	isPause = true;
}

void GameScene::Update()
{
	curTower = bm->SetCurrTower();
	if (curTower != NULL)
	{
		if (curTower->image != NULL)
		{
			ccTower = *curTower;
		}
	}
	mouseRC = RectMake(mousePos.x, mousePos.y, 20, 20);

}

void GameScene::Render(HDC hdc)
{
	HBRUSH hBrush, hOldBrush;
	hBrush = CreateSolidBrush(RGB(30, 30, 30));
	hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);
	Rectangle(hdc, 0, 0, WINWIDTH, WINHEIGHT);
	SelectObject(hdc, hOldBrush);
	DeleteObject(hBrush);
	DeleteObject(hOldBrush);

	map->TotalRender(hdc);

	bm->Render(hdc);

	if (ccTower.image != NULL)
		ccTower.image->RenderSize(hdc, mousePos.x, mousePos.y, ccTower.fX, ccTower.fY, 20, 20);
	
}

void GameScene::Release()
{
}

void GameScene::SetCurrTower()
{
	
}
