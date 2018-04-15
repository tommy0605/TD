#include "stdafx.h"

void GameScene::Init()
{
	curTower = new Tower;
	endPos = { 9999, 9999 };
	startPos = { 9999,9999 };
	endRect = { 9999,9999,9999,9999 };
	mouseRC = RectMake(mousePos.x, mousePos.y, 20, 20);
	bm = new BuildingManager;
	bm->Init();
	map = new MapTool;
	map->SetTile();
	map->LoadMap();
	map->SetSE();
	map->SetIsStart(true);
	em = new EnemyManager;
	em->Init(map);
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
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		map->SetIsStart(true);
	}
	if(map->GetIsStart())
		map->PathFinder();
	for (int i = 0; i < bm->GetUsingTowerList().size(); i++)
	{
		map->SetTowerClosedMap(bm->GetUsingTowerList()[i]->rc);
	}

	if (map->GetIsStart() == false)
	{
		em->Update();
	}
	for (int i = 0; i < em->GetEnemyLsit().size(); i++)
	{
		bm->Attack(em->GetEnemyLsit()[i]->GetPos());
	}
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
	{
		//ccTower.image->RenderSize(hdc, mousePos.x, mousePos.y, ccTower.fX, ccTower.fY, 28, 28);
		if (mousePos.x < TWINWIDTH - 15 && mousePos.x > 15 && mousePos.y < TWINWIDTH - 15 && mousePos.y > 15 && map->CheckTowerClosedMap(RectMake(map->GetMouseRect().left, map->GetMouseRect().top, 25,25)))
		{
			ccTower.image->RenderSize(hdc, map->GetMouseRect().left+1, map->GetMouseRect().top+1, ccTower.fX, ccTower.fY, 25, 25);
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				bm->SetTowerOnMap(ccTower, map->GetMouseRect().left, map->GetMouseRect().top);
			}
		}
	}
	if (map->GetEndTileRect().top != NULL)
	{
		endPos.x = map->GetEndTileRect().left - 15;
		endPos.y = map->GetEndTileRect().top - 15;
		endRect.left = endPos.x;
		endRect.top = endPos.y;
		endRect.right = endPos.x + 45;
		endRect.bottom = endPos.y + 45;
		IMAGEMANAGER->FindImage("base")->RenderSize(hdc, endPos.x, endPos.y, 2, 0, 45,45);
	}
	em->Render(hdc);
}

void GameScene::Release()
{

}


